#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_INPUT 262144
# define MAX 2048
# define TRUE 1
# define FREE(X) if(X) free((void*)X)
/* _BSD_MACHINE_SIGNAL_H_ */
# if defined (__i386__) || defined(__x86_64__)
# include "i386/signal.h"
# else
#error architecture not supported
#endif

/* --------------------------------- minishell ------------------------------ */

# include "../zlibft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "struct.h"
# include "lexer.h"
# include "exec.h"
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

/* --------------------------------- minishell.c ---------------------------- */

extern int	g_last_exit_code;

int			interactive_mode(t_minishell *shell);
void		initialize_struct(t_cmdline *command);
void		extract_redirections(char *str_line, t_cmdline *command);
void		print_debug(t_cmdline *cmdline, char **command);
t_cmdline	*parsecmd(const char *strline);

/* --------------------------------- signal --------------------------------- */

void		handle_sigint(int sig);
void		handle_sigquit(void);

#endif
