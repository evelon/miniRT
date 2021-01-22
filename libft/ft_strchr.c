/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:25:22 by jolim             #+#    #+#             */
/*   Updated: 2020/10/07 23:53:33 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	p;

	p = 0;
	while (*(str + p))
	{
		if (*(str + p) == (char)c)
			return ((char *)str + p);
		p++;
	}
	if (c == '\0')
		return ((char *)str + p);
	return (NULL);
}
