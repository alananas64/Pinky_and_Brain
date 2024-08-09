#include "../../inc/builtin.h"

static char	*get_value_of_certin_key(t_environment **list, char *key)
{
	t_environment *env_list = *list;
	while(env_list)
	{
		char *temp = ft_strnstr(env_list->key, key, ft_stop_in_equal(env_list->key));
		if ((temp) && (ft_strncmp(temp, key, ft_stop_in_equal(env_list->key)) == 0))
			return(env_list->value);
		else
			env_list = env_list->next;
	}
	return(NULL);
}

void	pwd_command(t_environment *env)
{
	printf("%s\n", get_value_of_certin_key(&env, "PWD"));
}

// int main(int arc, char **arg, char **env)
// {
// 	t_environment *test;
// 	test = env_command(env);
// 	pwd_command(test);
// }
