#include "../inc/minishell.h"

int	interactive_mode(void)
{
	char		*user_input;
	char		**command; /* will run the command */

	while (1)
	{
		user_input = readline("minishell-v1$ ");
		if (!user_input)
			return (perror("realine error"), 126);
		printf ("\tuser_input: {%s}\n", user_input);
		command = lexer(user_input);
		int i = 0; // debugging while loop
		while(command[i])
		{
			printf("string[%i] = {%s}\n", i, command[i]);
			i++;
		}
		free (user_input);
	}

	return (0);
}

int	main(int ac, char **av)
{
	if (1 < ac)
		return (printf("%s: %s: is a file or a directory", av[0], av[1]), 126); /* minishell does not take args */
	if (interactive_mode())
		return (printf ("vegy sed!"), 126); /* returns a random value does not have a meaning */
	return (0);
}
//ls -la libft | cat input.txt
// user_input = "echo hello | echo he\'ll\'o";
//cc -lreadline src/minishell.c src/parse/*.c -o minishell

/**
 * qoutes or not (double and single)
 * expansion $ ($PATH $HOME) get it from env
 *
*/

/**
 * command
 * flags
 * piped or not
*/

/**
 * $ " ' ! < >
 * << (heredoc)
 * >> < > redirections
 *
 * "   '$HOME' "
*/
