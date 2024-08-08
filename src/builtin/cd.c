#include "../../inc/builtin.h"
//change directory
// cd with only a relative or absolute path
// cd without any options or args takes u to root
//cd / or ~ takes u to root abey!!!! what is the difference
//cd .. goes back
// cd - do smth idk
/**
 * cd [directory]
 * cd ~
 * cd /path/to/directory
 * cd ..      change to parent directory
 * cd -  change to the previous working directory
 *
*/

char	*get_value_of_certin_key(t_environment **list, char *key)
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

void	cd_command(t_environment *env, char *arg_after_cd)
{
	char *path;

	// debug:
	char cwd[256];

	if ((!arg_after_cd))// go to the home dir path
	{
		path = get_value_of_certin_key(&env, "HOME");
		printf("\n\nthe path u r putting is : %s\n\n\n", path);
		chdir(path);
	}
	if (arg_after_cd)
	{
		chdir(arg_after_cd);
		//debug:
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("Current working directory: %s\n", cwd);
		else
			return;
	}
}

int main(int arc, char **arg, char **env)
{
	t_environment *test;
	test = env_command(env);
	cd_command(test, arg[1]);
}

