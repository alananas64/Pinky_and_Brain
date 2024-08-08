#include "libft.h"

int	is_empty(const char	*str)
{
	if (!str)
		return (1);
	while (*str)
		if (!is_space(*(str++)))
			return (0);
	return (1);
}
