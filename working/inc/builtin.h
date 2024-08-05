#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"
# include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_builtins
{
	char				*content;
	struct s_builtins	*next;
	// 	char	*key;
	// 	char	*value;
} t_builtins;

/*---------------------env.c---------------------*/
t_builtins *env_command(char **env);
void		print(t_builtins *root);
void	add_node_at_end(t_builtins **lst, t_builtins *new);
t_builtins	*create_new_node(void *content);
#endif

