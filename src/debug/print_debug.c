#include "debug.h"

void	wr_color(const char *color, const char *format, ...)
{
	va_list	args;
	char buffer[1024];

	va_start(args, format);
	printf("%s", color);
	vsnprintf(buffer, 1024, format, args);
	fputs(buffer, stdout);
	printf("%s", RESET);
	va_end(args);
}

void	print_debug(t_cmdline *cmdline, char **command)
{
	t_cmdline	*tmpcmd;
	int			i;

	i = -1;
	tmpcmd = cmdline;
	(void)command;
	while (tmpcmd != NULL)
	{
		if (tmpcmd->user_input)
			wr_color (CYAN, "\tuser_input: {%s}\n", tmpcmd->user_input);
		if (tmpcmd->input_redirect)
			wr_color (RED, "input redirect: {%s}\n", tmpcmd->input_redirect);
		if (tmpcmd->output_redirect)
			wr_color (RED, "output redirect: {%s}\n", tmpcmd->output_redirect);
		tmpcmd = tmpcmd->next;
	}
	// while (command[++i]) // debugging while loop
	// 	wr_color (MAGENTA, "cmd[%i] = {%s}\n", i, command[i]);
}
