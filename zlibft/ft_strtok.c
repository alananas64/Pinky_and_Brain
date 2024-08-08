#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	char		*delim_ptr;
	static char	*save_ptr = NULL;

	if (str == NULL)
		str = save_ptr;
	if (str == NULL || *str == '\0')
		return (NULL);
	delim_ptr = ft_strnstr(str, delim, ft_strlen(delim));
	if (delim_ptr == NULL)
		return (save_ptr = NULL, str);
	*delim_ptr = '\0';
	save_ptr = delim_ptr + ft_strlen(delim);
	return (str);
}
