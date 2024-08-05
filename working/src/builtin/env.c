#include "../../inc/builtin.h"

t_builtins	*create_new_node(void *content)
{
	t_builtins	*newnode;

	newnode = (t_builtins *)malloc(sizeof(t_builtins));
	if (!(newnode))
		return (NULL);
	newnode -> content = content;
	newnode -> next = NULL;
	return (newnode);
}

t_builtins	*find_last_node(t_builtins *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	add_node_at_end(t_builtins **lst, t_builtins *new)
{
	t_builtins	*last;

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

void	print(t_builtins *root)
{
	while (root != NULL)
	{
		printf("%s\n", root->content);
		root = root->next;
	}
}

t_builtins *env_command(char **env)
{
	int	i;
	t_builtins	*env_key_value;

	i = 0;
	env_key_value = NULL;
	while (env[i])
	{
		add_node_at_end(&env_key_value, create_new_node(env[i]));
		i++;
	}
	// print(env_key_value);
	return(env_key_value);
}
// int main(int arc, char **arg, char **env)
// {
// 	env_command(env);
// }
