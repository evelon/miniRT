/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:25:47 by jolim             #+#    #+#             */
/*   Updated: 2020/10/07 23:53:10 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	p;

	p = 0;
	while (p < n)
	{
		if (*((unsigned char *)s + p) == (unsigned char)c)
			return ((unsigned char *)s + p);
		p++;
	}
	return (NULL);
}
