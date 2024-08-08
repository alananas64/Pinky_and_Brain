#include "../inc/minishell.h"

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
/**
 * Function to handle signals
 * Resets the readline user input prompt for interactive signal handling.
*/
void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	// rl_replace_line("", 0);
	rl_redisplay();
}

/* ignore_sigquit:
*	Replaces SIGQUIT signals (ctrl-\) with SIG_IGN to ignore
*	the signal.
*/
void	handle_sigquit(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}
