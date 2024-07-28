#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_INPUT 262144
# define MAX 2048

# include "lexer.h"
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../zlibft/libft.h"

/* --------------------------------- minishell ------------------------------ */

# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

/* --------------------------------- minishell ------------------------------ */

/* --------------------------------- minishell ------------------------------ */

/* --------------------------------- minishell ------------------------------ */

// int		ft_atoi(const char *nptr);
// char	*ft_strdup(const char *s1);
// size_t	ft_strlen(const char *s);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// void	ft_putchar_fd(char c, int fd);
// void	ft_putstr_fd(char *s, int fd);

/* --------------------------------- builtin -------------------------------- */

char	**get_env(void);
char	*get_path(void);

/* --------------------------------- builtin -------------------------------- */


/* --------------------------------- minishell ------------------------------ */

/* --------------------------------- parser --------------------------------- */
/* --------------------------------- parser --------------------------------- */

/* --------------------------------- exec ----------------------------------- */

// void execute_command(t_command *cmd, minishell *shell);

/* --------------------------------- exec ----------------------------------- */

#endif
