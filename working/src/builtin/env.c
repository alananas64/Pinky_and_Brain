#include "../../inc/builtin.h"

t_environment	*create_new_node(void *key, void *value)
{
	t_environment	*newnode;

	newnode = (t_environment *)malloc(sizeof(t_environment));
	if (!(newnode))
		return (NULL);
	newnode ->key = key;
	newnode ->value = value;
	newnode -> next = NULL;
	return (newnode);
}

t_environment	*find_last_node(t_environment *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	add_node_at_end(t_environment **lst, t_environment *new)
{
	t_environment	*last;

	if ((lst == NULL) || (new == NULL))
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = find_last_node(*lst);
	last -> next = new;
}

void	print(t_environment *root)
{
	while (root != NULL)
	{
		printf("%s%s\n", root->key, root->value);
		root = root->next;
	}
}

t_environment *env_command(char **env)
{
	int				j;
	int				i;
	int				offset;
	char			*key;
	char			*value;
	t_environment	*newnode;
	t_environment	*env_key_value;

	j = 0;
	offset = 0;
	env_key_value = NULL;
	while (env[j])
	{
		i = 0;
		i = ft_stop_in_equal(env[j]);
		key = copying_the_key(env[j], i);
		value = copying_value_of_key(string_after_finding_c(env[j], '='));
		newnode = create_new_node(key, value);
		add_node_at_end(&env_key_value, newnode);
		j++;
	}
	return(env_key_value);
}

// int main(int arc, char **arg, char **env)
// {
// 	t_environment *test;

// 	test = env_command(env);
// 	print(test);
// }
