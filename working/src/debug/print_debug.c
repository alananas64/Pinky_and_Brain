#include "../../inc/debug.h"
// #include "../../inc/struct.h"

void	wr_color(const char *color, const char *format, ...)
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

void	print_debug(t_cmdline *cmdline)
{
	if (cmdline->user_input)
		wr_color (GREEN, "\tuser_input: {%s}\n", cmdline->user_input);
	if (cmdline->input_redirect)
		wr_color (GREEN, "input redirect: {%s}\n", cmdline->input_redirect);
	if (cmdline->output_redirect)
		wr_color (GREEN, "output redirect: {%s}\n", cmdline->output_redirect);

}
