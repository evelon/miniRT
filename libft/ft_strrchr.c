/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:57:02 by jolim             #+#    #+#             */
/*   Updated: 2020/10/07 23:54:15 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	p;

	p = 0;
	while (*(str + p))
		p++;
	while (p >= 0)
	{
		if (*(str + p) == (char)c)
			return ((char *)str + p);
		p--;
	}
	return (NULL);
}
