/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:06:20 by nosman            #+#    #+#             */
/*   Updated: 2024/07/15 15:14:52 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if ((!count) || (!size))
	{
		memory = malloc(1);
		return (memory);
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	memory = malloc(size * count);
	if (!(memory))
		return (NULL);
	else
		ft_bzero(memory, size * count);
	return (memory);
}
