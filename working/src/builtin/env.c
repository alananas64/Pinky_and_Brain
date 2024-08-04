#include "../../inc/builtin.h"

typedef struct s_list
{
	char	*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!(newnode))
		return (NULL);
	newnode -> content = content;
	newnode -> next = NULL;
	return (newnode);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if ((lst == NULL) || (new == NULL))
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new;
}

void	print(t_list *root)
{
	while (root != NULL)
	{
		printf("%s\n", root->content);
		root = root->next;
	}
}

void env_command(char **env)
{
	int	i;
	t_list	*env_key_value;

	i = 0;
	// env_key_value = NULL; // is it important to set it as null in the begining
	while (env[i])
	{
		ft_lstadd_back(&env_key_value, ft_lstnew(env[i]));
		i++;
	}
	print(env_key_value);
	return (0);
}
