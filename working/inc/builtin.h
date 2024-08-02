#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"
# include <unistd.h>

char	**get_env(void);
char	*get_path(void);

#endif
