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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((s1[i] != '\0') || (s2[i] != '\0')) && (i < n - 1)
		&& (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/**
 * loops in env linked list until it reached the i postion
 * when i delet the node by :
 *		make the node before i points to the node after i
 *		make i points to NULL
*/
t_list	delete_node_i(t_list *env_list, int i)
{
	int j;

	j = 0;
	while(j < i)
		j++;
	if(j == i)
	{
		env_list[i - 1]->next = env_list[i]->next;
		env_list[i]->next = NULL;
	}
	return(t_list);
}
/**
 * roam around env linked list
 * look for the key
 * delet that node
 * return the new env linked list
 *
 * takes 2 params:
 * 1)env linked list
 * 2)the key that u want to delet
*/

t_list	*unset_command(t_list *env_list, char *key)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(env_list[i])
	{
		// env_list[i][j] != '='
		if(ft_strncmp(env_list[i], key, ft_strlen(key)) != 0)
			i++;
		else
			env_list = delete_node_i(env_list, i);
	}
	return(env_list);
}
