/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:50:44 by jolim             #+#    #+#             */
/*   Updated: 2020/10/10 16:34:57 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;

	if (count == 0 || size == 0)
	{
		if (!(new = malloc(0)))
			return (NULL);
		return (new);
	}
	if (!(new = malloc(count * size)))
		return (NULL);
	ft_bzero(new, count * size);
	return (new);
}
