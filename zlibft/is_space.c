#include "libft.h"

int	is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r');
}
