/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:09:27 by jolim             #+#    #+#             */
/*   Updated: 2021/01/03 20:34:32 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	p;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		if (!(sub = (char *)malloc(1 * sizeof(char))))
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	p = 0;
	if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (len > p && (sub + p) != NULL)
	{
		*(sub + p) = *(s + start + p);
		p++;
	}
	*(sub + p) = '\0';
	return (sub);
}
