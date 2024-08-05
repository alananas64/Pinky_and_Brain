#include "../../inc/builtin.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_isalpha_underscore(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123) || (c == 95))
		return (1);
	else
		return (0);
}

/**
 * takes 2 params :
 * 1) list of env to append to it
 * 2) args that the user input in terminal cc the string that has key and value
*/
void export_command(t_builtins **list, char *arg)
{
	int i;
	int j;
	int r;
	int value_len;
	char *key;
	char *value;

	i = 0;
	j = 0;
	r = 0;
	t_builtins *env_list = *list;
	value = NULL;
	if (!arg)
		return;
	while(arg[i] != '\0')
	{
		while((arg[i] != '\0') && (arg[i] != '='))
		{
			if (ft_isalpha_underscore(arg[i]) == 1)
				i++;
			else
			{
				printf("error your key is not alpha\n");
				return;
			}
		}
		key = (char *)malloc(sizeof(char) * i + 1);
		while((arg[i] != '\0') && (j < i))
		{
			key[j] = arg[j];
			j++;
		}
		if(arg[i] == '=')
			i++;
		value_len = ft_strlen(arg) - i + 1;
		value = (char *)malloc(sizeof(char) * value_len + 1);
		while(arg[i])
		{
			value[r] = arg[i];
			r++;
			i++;
		}
	}
	if(arg[i] == '\0')
		add_node_at_end(&env_list, create_new_node(arg));
}
int main(int arc, char **arg, char **env)
{
	t_builtins	*env_before_export;
	t_builtins	*exported_env;
	char *token_string;

	token_string = "EXPIRE=hello=uncle";
	env_before_export = env_command(env);
	export_command(&env_before_export, token_string);
	print(env_before_export);
}


// last line in env is :
// _=/Users/nosman/Desktop/work/nredirec_yenv_yecho/src/builtin/./a.out
