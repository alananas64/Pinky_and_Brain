#include "libft.h"

char	*str_clone(const char *source)
{
	char	*clone;

	clone = (char *)malloc (ft_strlen(source) + 1);
	ft_strlcpy (clone, source, ft_strlen(source));
	return (clone);
}
