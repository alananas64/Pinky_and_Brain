#include "../inc/minishell.h"

int	interactive_mode(void)
{
	char		*user_input;
	char		**command;
	t_cmdline	command_struct;

	while (1)
	{
		user_input = readline("😎minishell-v1$ ");
		if (!user_input)
			return (perror("realine error"), 126);
		printf ("\tuser_input: {%s}\n", user_input);
		command = lexer(user_input);
		initialize_struct(&command_struct);
		extract_redirections(*command , &command_struct);
		printf("Input redirect: %s\n", command_struct.input_redirect);
		printf("Output redirect: %s\n", command_struct.output_redirect);
		free(command_struct.input_redirect);//-----------------------------free function------------------------
		free(command_struct.output_redirect);//-----------------------------free function------------------------
	// 	int i = 0; // debugging while loop
	// 	while(command[i])
	// 	{
	// 		printf("string[%i] = {%s}\n", i, command[i]);
	// 		i++;
	// 	}
	// 	free (user_input);//-----------------------------free function------------------------
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
