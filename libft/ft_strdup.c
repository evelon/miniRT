/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:13:11 by jolim             #+#    #+#             */
/*   Updated: 2020/10/10 11:32:22 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		p;

	len = ft_strlen(s1);
	if (!(s2 = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	p = 0;
	while (p <= len)
	{
		*(s2 + p) = *(s1 + p);
		p++;
	}
	return (s2);
}
