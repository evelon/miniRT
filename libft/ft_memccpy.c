/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:48:59 by jolim             #+#    #+#             */
/*   Updated: 2020/10/08 01:32:43 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			p;
	unsigned char	*dst_p;
	unsigned char	*src_p;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	p = 0;
	while (p < n)
	{
		if (src_p[p] == (unsigned char)c)
		{
			dst_p[p] = src_p[p];
			return (dst_p + p + 1);
		}
		dst_p[p] = src_p[p];
		p++;
	}
	return (NULL);
}
