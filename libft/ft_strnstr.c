/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:37:09 by jolim             #+#    #+#             */
/*   Updated: 2020/10/10 19:18:36 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	p;

	h_len = (ft_strlen(haystack) > len) ? len : ft_strlen(haystack);
	if (*needle == '\0')
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	if (len < n_len)
		return (NULL);
	p = 0;
	while (p + n_len <= h_len)
	{
		if (ft_memcmp((haystack + p), needle, n_len) == 0)
			return ((char *)(haystack + p));
		p++;
	}
	return (NULL);
}
