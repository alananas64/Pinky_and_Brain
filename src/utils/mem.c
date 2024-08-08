#include "utils.h"
#include <stdio.h>

void	free_struct(t_cmdline *cmdline)
{
	if (!cmdline)
	{
		printf("invlid read cmdline\n");
		return ;
	}
	if (cmdline->input_redirect)
		free (cmdline->input_redirect);
	if (cmdline->output_redirect)
		free (cmdline->output_redirect);
	if (cmdline->user_input)
		free (cmdline->user_input);
}
