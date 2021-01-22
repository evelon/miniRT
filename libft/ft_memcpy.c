/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:39:12 by jolim             #+#    #+#             */
/*   Updated: 2020/10/09 05:37:47 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	p;

	if (!dst && !src)
		return (NULL);
	p = 0;
	while (p < n)
	{
		*((unsigned char *)dst + p) = *((unsigned char *)src + p);
		p++;
	}
	return (dst);
}
