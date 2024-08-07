/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:03 by nosman            #+#    #+#             */
/*   Updated: 2024/07/23 13:55:07 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	n;
	char	*str;
	int		i;

	n = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == n)
		{
			return (str + i);
		}
		i++;
	}
	if (str[i] == n)
	{
		return (str + i);
	}
	return (NULL);
}

#include <stdio.h>

int main()
{
	printf("%s", ft_strchr("hello", 'e'));
}
