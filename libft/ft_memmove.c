/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:25:28 by jolim             #+#    #+#             */
/*   Updated: 2020/10/10 15:20:22 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			p;
	unsigned char	*d_c;
	unsigned char	*s_c;

	d_c = (unsigned char *)dest;
	s_c = (unsigned char *)src;
	if (n == 0)
		return (dest);
	if (!d_c && !s_c)
		return (dest);
	p = n;
	if (d_c > s_c)
	{
		while (--p > 0)
			*(d_c + p) = *(s_c + p);
		*(d_c + p) = *(s_c + p);
		return (dest);
	}
	p = 0;
	while (p < n)
	{
		*(d_c + p) = *(s_c + p);
		p++;
	}
	return (dest);
}
