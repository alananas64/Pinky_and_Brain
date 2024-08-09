#include "exec.h"

/**
 * Function to execute redirections.
 * Checks which type of redirection the user
 * input to determine appropriate flags
*/
void	executeredirection(t_cmdline *command, char *userInput)
{
	int		files[2];
	pid_t	pid;

	if ((pid = fork()) == 0)
	{
		files[1]  = open(command->input_redirect, O_RDONLY, 0666);
		if ((strstr(userInput, ">>")))
			files[2] = open(command->output_redirect, O_WRONLY | O_CREAT
				| O_APPEND, 0666);
		else
			files[2] = open(command->output_redirect, O_WRONLY | O_TRUNC
				| O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR, 0666);
		dup2(files[1], 0);
		dup2(files[2], 1);
		if( execv(*command->arguments, command->arguments) < 0 )
			(perror(*command->arguments), exit(EXIT_FAILURE));
	}
	else
	{
		close(files[1]);
		close(files[2]);
		while (waitpid(pid,0,0) <= 0)
			;
	}
}

int	execute_external_command(t_cmdline *command, char *userinput)
{
	if (command == NULL || userinput == NULL) {
		fprintf(stderr, "Invalid input parameters\n");
		return -1;
	}
	if (strchr(userinput, '>') || strchr(userinput, '<') || strpbrk(userinput, ">>")) {
		executeredirection(command, userinput);
	} else {
		pid_t pid = fork();

		if (pid == -1) {
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0) { /* Child process */
			if (command->arguments == NULL) {
				fprintf(stderr, "No arguments provided\n");
				exit(EXIT_FAILURE);
			}

			for (int i = 0; i < command->argcount; i++) {
				printf("Argument %d: %s\n", i, command->arguments[i]);
			}

			if (execv(command->exec_path, (char *const *)command->arguments) < 0) {
				perror(command->exec_path);
				exit(EXIT_FAILURE);
			}
		} else { /* Parent process */
			if (command->background == 1) {
				int status;
				while (waitpid(pid, &status, WNOHANG) == 0) {
					// Perform other tasks or sleep for a short period
					usleep(10000); // Sleep for 10 milliseconds
				}
				command->background = 0;
			} else {
				waitpid(pid, NULL, 0);
			}
		}
	}
	return 0;
}

/**
 * Execute builtin and external commands
*/
int	execute_external_command(t_cmdline *command, char *userinput)
{
	int		i;
	pid_t	pid;
	
	if (strchr(userinput, '>') || strchr(userinput, '<')
		|| strpbrk(userinput, ">>"))
		executeredirection(command, userinput);
	else
	{
		pid = fork();
		if (-1 == pid)
			(perror("fork"), exit(EXIT_FAILURE));
		else if (0 == pid) /** child process */
		{
			if (execv(*command->arguments, command->arguments) < 0)
				(perror(*command->arguments), exit(EXIT_FAILURE));
		}
		else /** parent process */
		{
			if (command->background == 1)
			{
				while (waitpid(pid, 0, 0) <= 0)
					; /* wait for the child process to terminate */
				command->background = 0;
			}
		}
	}
	return (0);
}

void	execute_command(t_minishell *shell, char **parsed_input)
{
	int	i = -1;
	
	while (shell->commands->user_input[++i])
	{
		if (strcmp(parsed_input[0], "echo") == 0)
			execute_echo(parsed_input);
		else if (strcmp(parsed_input[0], "cd") == 0)
			execute_cd(parsed_input);
		else if (strcmp(parsed_input[0], "pwd") == 0)
			execute_pwd(parsed_input);
		else if (strcmp(parsed_input[0], "export") == 0)
			execute_export(parsed_input);
		else if (strcmp(parsed_input[0], "unset") == 0)
			execute_unset(parsed_input);
		else if (strcmp(parsed_input[0], "env") == 0)
			execute_env(parsed_input);
		else if (strcmp(parsed_input[0], "exit") == 0)
			execute_exit(parsed_input);
		else
		{
			shell->commands->exec_path = search_executable(parsed_input[0]);
			execute_external_command(shell->commands->exec_path,
				shell->commands->user_input);
		}
	}
}

/* Function to execute a command */
void	execute_commands(t_minishell *shell, char **parsed_input,
	t_environment *var)
{
	if (!check_syntax(shell->commands->user_input))
		executeVariables(shell->commands->user_input, var);
	else
	{
		if (strchr(shell->commands->user_input, '|') != NULL)
			runPipedCommands(shell, shell->commands->user_input);
		else
		{
			expandargs(shell);
			expandVariables(shell, var);
			executeCommands(shell, shell->commands->user_input, var);
		}
	}
}
