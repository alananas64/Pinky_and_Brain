#include "../inc/minishell.h"
#include "../inc/struct.h"

int	interactive_mode(void)
{
	char		**command;
	t_cmdline	cmdline;

	while (1)
	{
		cmdline.user_input = readline("😎minishell-v1$ ");
		if (!cmdline.user_input)
			return (perror("realine error"), 126);
		command = lexer(cmdline.user_input);
		initialize_struct(&cmdline);

		extract_redirections(*command , &cmdline);
		print_debug(&cmdline);
		free(cmdline.input_redirect);
		free(cmdline.output_redirect);
		// int i = -1; // debugging while loop
		// while(command[++i])
		// 	printf("string[%i] = {%s}\n", i, command[i]);
		// free (user_input);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (1 < ac)
		return (printf("%s: %s: is a file or a directory", av[0], av[1]), 126);
	if (interactive_mode())
		return (printf ("vegy sed!"), 126); /* returns a random value does not have a meaning */
	return (0);
}

/**
 * --> SIGNALS <--
 * 0: The command executed successfully.
 * 1: The shell encountered a syntax error or an error in a startup file (e.g.,
	~/.bashrc).
 * 2: The shell encountered an error while reading input (e.g., Ctrl+D was
 	pressed).
 * 3-125: The command failed, and the specific value indicates the type of
 	error.
 * 126: The command was not executable (e.g., it was a directory).
	minishell does not take args
 * 127: The command was not found.
 * 128-255: The command was terminated by a signal (e.g., Ctrl+C).
*/