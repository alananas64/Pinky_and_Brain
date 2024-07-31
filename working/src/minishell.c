#include "../inc/minishell.h"

// void wr_color(const char *color, const char *format, ...)
// {
// 	va_list	args;

// 	va_start(args, format);
// 	printf("%s", color);
// 	vfprintf(stdout, format, args);
// 	printf("%s", RESET_COLOR);
// 	va_end(args);
// }

void wr_color(const char *color, const char *format, ...)
{
	va_list	args;
	char buffer[1024];

	va_start(args, format);
	printf("%s", color);
	vsnprintf(buffer, 1024, format, args);
	fputs(buffer, stdout);
	printf("%s", RESET_COLOR);
	va_end(args);
}

/**
 * RED
 * GREEN
 * YELLOW
 * BLUE
 * MAGENTA
 * CYAN
*/

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
		wr_color (GREEN, "\tuser_input: {%s}\n", user_input);
		command = lexer(user_input);
		initialize_struct(&command_struct);
		extract_redirections(*command , &command_struct);
		printf("Input redirect: {%s}\n", command_struct.input_redirect);
		printf("Output redirect: {%s}\n", command_struct.output_redirect);
		free(command_struct.input_redirect);	//-----------------------------free function------------------------
		free(command_struct.output_redirect);	//-----------------------------free function------------------------
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
