#include "minishell.h"
#include "lexer.h"

/* Set up signal handlers */
/* Function to initialize the shell */
void	init_shell(t_minishell *shell, char **env)
{
	struct sigaction	act;
	
	handle_sigquit();
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &handle_sigint;
	sigaction(SIGINT, &act, NULL);

	shell->env = env_command(env);
	shell->pwd = getcwd(NULL, 0);
	shell->commands->cmd = NULL;
	shell->commands->user_input = NULL;
	shell->commands->input_redirect = NULL;
	shell->commands->output_redirect = NULL;
}

int	interactive_mode(t_minishell *shell)
{
	while (1)
	{
		shell->commands->user_input = readline("minishell$> ");
		if (!shell->commands->user_input)
			return (printf("exit\n"), exit (1), 1);
		shell->commands->cmd = lexer(shell->commands->user_input);
		printf("input = {%s}\n", shell->commands->user_input);
		if (tokenization(shell, shell->commands->user_input) == 1)
			continue;
		extract_redirections(*shell->commands->cmd, shell->commands);
		shell->commands = parsecmd(command);


		print_debug(shell->commands, shell->commands->cmd);
		if (parse == 0)
			exec();
		else
		{
			printf("invalid syntax\n");
			free_struct(shell->commands);
		}
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
	shell->token = (t_token *)malloc(sizeof(t_token));
	shell->commands = (t_cmdline *)malloc(sizeof(t_cmdline));
	shell->env = (t_environment *)malloc(sizeof(t_environment));
	init_shell(shell, env);
	if (interactive_mode(shell))
		return (printf ("vegy sed!"), 126);
	return (0);
}
