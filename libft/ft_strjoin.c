/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:59:49 by jolim             #+#    #+#             */
/*   Updated: 2020/10/10 19:06:56 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		p;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(new = (char *)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	p = 0;
	while (p < len1)
	{
		*(new + p) = *(s1 + p);
		p++;
	}
	p = 0;
	while (p < len2)
	{
		*(new + len1 + p) = *(s2 + p);
		p++;
	}
	*(new + len1 + p) = '\0';
	return (new);
}
