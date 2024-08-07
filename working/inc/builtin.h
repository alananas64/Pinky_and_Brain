#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_environment
{
	char					*content;
	struct s_environment	*next;
	char					*key;
	char					*value;
} t_environment;

/*---------------------env.c---------------------*/

t_environment *env_command(char **env);
void		print(t_environment *root);
void	add_node_at_end(t_environment **lst, t_environment *new);
t_environment	*create_new_node(void *key, void *value);

/*--------------------export.c------------------*/
t_environment *export_command(t_environment **list, char *arg);
size_t	ft_stop_in_equal(const char *str);
char	*copying_value_of_key(char *src);
char	*copying_the_key(char *src, int i);
char	*copying_with_i_chars(char *src, char *dest, int i);
char	*string_after_finding_c(const char *s, int c);
int	check_key_is_valid(char *arg);
size_t	ft_stop_in_equal(const char *str);
int	ft_isalpha_is_underscore(int c);
size_t	ft_strlen(const char *str);

/*-------------------unset.c-------------------*/
t_environment *unset_command(t_environment **list, char *key);

#endif
