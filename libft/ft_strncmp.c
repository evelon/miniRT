/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:46:34 by jolim             #+#    #+#             */
/*   Updated: 2020/10/08 05:23:10 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	p;

	if (n == 0)
		return (0);
	p = 0;
	while ((*(s1 + p) == *(s2 + p)) && p < n - 1)
	{
		if (*(s1 + p) == '\0')
			return (0);
		p++;
	}
	return (*(unsigned char *)(s1 + p) - *(unsigned char *)(s2 + p));
}
