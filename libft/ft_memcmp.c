/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:25:35 by jolim             #+#    #+#             */
/*   Updated: 2020/10/13 11:35:29 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_p;
	unsigned char	*s2_p;
	size_t			p;
	int				dif;

	if (s1 == s2 && s1 != NULL)
		return (0);
	s1_p = (unsigned char *)s1;
	s2_p = (unsigned char *)s2;
	p = 0;
	while (p < n)
	{
		dif = *(s1_p + p) - *(s2_p + p);
		if (dif != 0)
			return (dif);
		p++;
	}
	return (0);
}
