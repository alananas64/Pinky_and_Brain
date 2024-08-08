#include "minishell.h"

/* Set up signal handlers */
/* Function to initialize the shell */
void	init_shell(t_minishell *shell, char **env)
{
	struct sigaction	act;
	
	handle_sigquit();
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &handle_sigint;
	sigaction(SIGINT, &act, NULL);

	shell->env = env_command(env); /* initialize environment variables */
	shell->pwd = getcwd(NULL, 0); /* initialize current working directory */
	shell->history->value = NULL;
	shell->commands->cmd = NULL;
	shell->commands->user_input = NULL;
	shell->commands->input_redirect = NULL;
	shell->commands->output_redirect = NULL;
}

int	interactive_mode(t_minishell *shell)
{
	char **command;

	while (1)
	{
		shell->commands->user_input = readline("minishell$> ");
		if (!shell->commands->user_input)
			return (printf("exit\n"), exit (1), 1);
		command = lexer(shell->commands->user_input);

		// shell->commands = parsecmd(command);
		extract_redirections(*command, shell->commands);
		print_debug(shell->commands, command);
		free_struct(shell->commands);
	}
	return (0);
}

/* grep "ERROR" log.txt 2>/dev/null | sort | uniq -c | sort -rn > error_counts.txt */
int	main (int ac, char **av, char **env)
{
	t_minishell	*shell;

	if (1 < ac)
		return (printf("%s: %s: is a file or a directory", av[0], av[1]), 126);
	printf ("{%s}: {%i}\n", av[0], getpid());
	shell = (t_minishell *)malloc(sizeof(t_minishell));
	shell = ft_memset(shell, 0, sizeof(shell));
	shell->history = (t_token *)malloc(sizeof(t_token));
	shell->commands = (t_cmdline *)malloc(sizeof(t_cmdline));
	shell->env = (t_environment *)malloc(sizeof(t_environment));
	init_shell(shell, env);
	if (interactive_mode(shell))
		return (printf ("vegy sed!"), 126);
	return (0);
}
