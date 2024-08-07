/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:51:35 by nosman            #+#    #+#             */
/*   Updated: 2024/06/25 14:41:12 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!(s))
		return (NULL);
	if (start >= ft_strlen(s)) // strlen(s) = 4 start = 6
		return (ft_strdup(""));
	if (len > ft_strlen(s)- start) // hello lo
		len = ft_strlen(s) - start;
	sub = (char *)malloc ((len + 1) * sizeof(char));
	if (!(sub))
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while ((s[start] != '\0') && (i < len))
		{
			sub[i] = s[start];
			start++;
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
