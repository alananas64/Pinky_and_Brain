#include "../../inc/builtin.h"

char	*string_after_finding_c(const char *s, int c) //printing after the c till the end
{
	char	n;
	char	*str;
	int		i;

	n = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == n)
		{
			i++; // added i++ so i print after the = not with it
			return (str + i);
		}
		i++;
	}
	if (str[i] == n)
		return (str + i);
	return (NULL);
}
static char	*copying_with_i_chars(char *src, char *dest, int i)
{
	unsigned int	j;

	j = 0;
	while ((src[j] != '\0') && (j <= i))
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*copying_the_key(char *src, int i)
{
	// unsigned int	i;
	char			*dest;

	// i = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!(dest))
		return (NULL);
	return (copying_with_i_chars(src, dest, i));
}
char	*copying_value_of_key(char *src)
{
	unsigned int	i;
	char			*dest;

	i = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!(dest))
		return (NULL);
	return (copying_with_i_chars(src, dest, i));
}

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
static size_t	ft_stop_in_equal(const char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] != '\0') && (str[i] != '=')) // protection of what if did not find = sign
	{
		i++;
	}
	return (i);
}

static int	ft_isalpha_is_underscore(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123) || (c == 95))
		return (1);
	else
		return (0);
}

static int	check_key_is_valid(char *arg)
{
	int i;

	i = 0;
	while((arg[i] != '\0') && (arg[i] != '='))
	{
		if (ft_isalpha_is_underscore(arg[i]) == 1)
			i++;
		else
		{
			// printf("error your key is not alpha\n");
			return(1);
		}
	}
	return(0);
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
	char *key;
	char *value;

	i = 0;
	j = 0;
	t_builtins *env_list = *list;
	value = NULL;
	if (!arg)
		return;
	while(arg[i] != '\0')
	{
		if (check_key_is_valid(arg) == 1)
		{
			printf("error your key is not alpha\n\n\n");
			return ;
		}
		i = ft_stop_in_equal(arg);
		key = copying_the_key(arg, i);
		value = copying_value_of_key(string_after_finding_c(arg, '='));
		// printf("\n\n\n____key is____%s____________\n\n\n", key);
		// printf("\n\n\n_____value is______%s____________\n\n\n", value);
		break; // i  need to stop the loop properly
	}
	// if(arg[i] == '\0') // if no error occcured add the node to the end of the env list
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
