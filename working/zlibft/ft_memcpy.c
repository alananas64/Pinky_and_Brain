/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:04:27 by nosman            #+#    #+#             */
/*   Updated: 2023/11/22 14:11:45 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*des;
	char	*sr;

	if ((!dest) && (!src))
		return (NULL);
	des = (char *)dest;
	sr = (char *)src;
	i = 0;
	while (i < n)
	{
		des[i] = sr[i];
		i++;
	}
	return (des);
}
