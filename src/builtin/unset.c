#include "builtin.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((s1[i] != '\0') || (s2[i] != '\0')) && (i < n - 1)
		&& (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)haystack;
	i = 0;
	j = 0;
	while ((str[i + j] != '\0') && (needle[j] != '\0') && (i < len)
		&& (i + j < len))
	{
		if (str[i + j] == needle[j])
			j++;
		else
		{
			i++;
			j = 0;
		}
	}
	if (needle[j] == '\0')
		return (str + i);
	else
		return (0);
}

// /**
//  * loops in env linked list until it reached the i postion
//  * when i delet the node by :
//  *		make the node before i points to the node after i
//  *		make i points to NULL
// */

void delete_content(void *content)
{
	free(content);
}

void delet_content_of_a_node(t_environment **lst, void (*del)(void*))
{
	if (!*lst || !del)
		return ;
	t_environment *temp = *lst;
	(del)(temp->key);
	(del)(temp->value);
	*lst = temp->next;
	free(temp);
}

// /**
//  * roam around env linked list
//  * look for the key
//  * delet that node
//  * return the new env linked list
//  *
//  * takes 2 params:
//  * 1)env linked list
//  * 2)the key that u want to delet
// */

t_environment *unset_command(t_environment **list, char *key)
{
	t_environment *env_list = *list;
	t_environment *prev = NULL;
	if (!key)
		return(*list);
	while(env_list)
	{
		char *temp = ft_strnstr(env_list->key, key, ft_stop_in_equal(env_list->key));
		if ((temp) && (ft_strncmp(temp, key, ft_stop_in_equal(env_list->key)) == 0))
		{
			if (prev)
				prev->next = env_list->next;
			else
				*list = env_list->next;
			delet_content_of_a_node(&env_list, delete_content);
			break;
		}
		else
		{
			prev = env_list;
			env_list = env_list->next;
		}
	}
	return(*list);
}

// int main(int arc, char **arg, char **env)
// {
// 	t_environment	*env_export;
// 	t_environment	*exported_env;
// 	char *token_string;
// 	char *key;

// 	token_string = "hi=hello";
// 	key="USER";
// 	env_export = env_command(env);
// 	printf("\n");
// 	print(env_export); // getting original env
// 	printf("\n\n\n\n");
// 	env_export= export_command(&env_export, token_string);
// 	print(env_export); // env after exporting
// 	printf("\n\n\n\n");
// 	env_export = unset_command(&env_export, key);
// 	print(env_export); //env after unset
// 	printf("\n\n\n\n");
// }
