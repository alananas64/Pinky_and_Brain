#include "exec.h"

int	ret;

// /* Function to execute an external command */
void	execute_external_command(char *executable_path, char **parsed_input)
{
	pid_t	pid;

	pid = fork();
	/* In child process */
	/* Execute external command */
	if (pid == 0)
		execve(executable_path, parsed_input, NULL);
	/* In parent process */
	/* Wait for child process to finish */
	else
		waitpid(pid, NULL, 0);
}

// /* Function to execute a command */
void	execute_command(char **parsed_input)
{
	char	*executable_path;

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
		executable_path = search_executable(parsed_input[0]);
		execute_external_command(executable_path, parsed_input);
	}
}

// /* Function to execute a built-in command */
// void	execute_builtin(char **parsed_input, t_cmdline cmdline)
// void	execute_builtin(char **parsed_input)
// {
// 	if (strcmp(parsed_input[0], "echo") == 0)
// 	{
// 		int i = 0;
// 		while (parsed_input[++i])
// 			printf("{%s}\n", parsed_input[i]);
// 		ft_putstr_fd("\n", 1);
// 	}
// 	else if (strcmp(parsed_input[0], "cd") == 0)
// 		chdir(parsed_input[1]);
// 	else if (strcmp(parsed_input[0], "pwd") == 0)
// 	{
// 		char cwd[1024];
// 		getcwd(cwd, 1024);
// 		printf("{%s}\n", cwd);
// 	}
// 	else if (strcmp(parsed_input[0], "export") == 0)
// 		setenv(parsed_input[1], parsed_input[2], 1);
// 	else if (strcmp(parsed_input[0], "unset") == 0)
// 		unsetenv(parsed_input[1]);
// 	else if (strcmp(parsed_input[0], "env") == 0)
// 	{
// 		/* Execute env command */
// 	}
// 	else if (strcmp(parsed_input[0], "exit") == 0)
// 		exit(ret);
// }

int exec()
{
	char *user_input;

	while (1)
	{
		user_input = readline ("MINISHELL$ ");
		if (!user_input)
			return (perror("read line error"), 1);
		printf ("user input: {%s}\n", user_input);
		add_history (user_input);
		while ()
			execute_command();
		free (user_input);
	}
	return (EXIT_SUCCESS);
}
