/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:07:51 by nosman            #+#    #+#             */
/*   Updated: 2023/11/25 18:53:04 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	m;
	size_t			i;

	str = (unsigned char *)s;
	m = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == m)
		{
			return (str + i);
		}
		else
		{
			i++;
		}
	}
	return (NULL);
}
