/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:16:29 by nosman            #+#    #+#             */
/*   Updated: 2024/05/05 10:35:05 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	n;
	char	*str;
	int		i;
	int		len;

	n = (char)c;
	str = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	len = i;
	while (len >= 0)
	{
		if (s[len] == n)
		{
			return (str + len);
		}
		len--;
	}
	return (NULL);
}
