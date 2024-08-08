#include "../../inc/builtin.h"

//this file has alot of functions( 9 functions) , needed to pe divided into 2 files
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

char	*copying_with_i_chars(char *src, char *dest, int i)
{
	int	j;

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
	char			*dest;

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

size_t	ft_stop_in_equal(const char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] != '\0') && (str[i] != '=')) // protection of what if did not find = sign
	{
		i++;
	}
	return (i);
}

int	ft_isalpha_is_underscore(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123) || (c == 95))
		return (1);
	else
		return (0);
}

int	check_key_is_valid(char *arg)
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
t_environment *export_command(t_environment **list, char *arg)
{
	int i;
	int j;
	char *key;
	char *value;

	i = 0;
	j = 0;
	t_environment *env_list = *list;
	value = NULL; // is this really needed?
	if (!arg)
		return(*list);
	while(arg[j] != '\0')
	{
		if (check_key_is_valid(arg) == 1)
		{
			printf("error your key is not alpha\n\n\n"); // we should get out here oe return or exit almoheem
		}
		i = ft_stop_in_equal(arg);
		key = copying_the_key(arg, i);
		value = copying_value_of_key(string_after_finding_c(arg, '='));
		j++;
	}
	add_node_at_end(&env_list, create_new_node(key, value));
	return(*list);
}

// int main(int arc, char **arg, char **env)
// {
// 	t_environment	*env_export;
// 	t_environment	*exported_env;
// 	char *token_string;

// 	token_string = "hi=hello";
// 	env_export = env_command(env);
// 	printf("\n\n\n\n");
// 	print(env_export); // original env
// 	printf("\n\n\n\n");
// 	env_export = export_command(&env_export, token_string);
// 	printf("\n\n\n\n");
// 	print(env_export); // env after exporting
// 	printf("\n\n\n\n");
// }
