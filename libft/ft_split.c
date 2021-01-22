/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 06:16:28 by jolim             #+#    #+#             */
/*   Updated: 2021/01/06 20:58:26 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *s, char c)
{
	int	count;

	count = 0;
	if (*s == '\0')
		return (count);
	if (*s != c)
		count++;
	while (*(s + 1))
	{
		if (*s == c && *(s + 1) != c)
			count++;
		s++;
	}
	return (count);
}

char		*woalloc(char *s, char c)
{
	char	*new;
	int		len;

	len = 0;
	while (*(s + len) != c && *(s + len) != '\0')
		len++;
	if (!(new = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	new[len] = '\0';
	while (len)
	{
		len--;
		new[len] = s[len];
	}
	return (new);
}

char		**spalloc(char *s, char c, int num)
{
	char	**new;
	int		n;

	if (!(new = (char **)malloc((num + 1) * sizeof(char *))))
		return (NULL);
	n = 0;
	while (n < num)
	{
		if (!(new[n] = woalloc(s, c)))
		{
			while (--n >= 0)
				free(new[n]);
			free(new);
			return (NULL);
		}
		while (*s != c && *s != '\0')
			s++;
		while (*s == c)
			s++;
		n++;
	}
	new[n] = NULL;
	return (new);
}

char		**ft_split(char const *s, char c)
{
	char	*s_p;
	int		wnum;

	if (s == NULL)
		return (NULL);
	s_p = (char *)s;
	while (*s_p == c && *s_p != '\0')
		s_p++;
	wnum = count(s_p, c);
	return (spalloc(s_p, c, wnum));
}

void		free_split(char **word)
{
	int	i;

	i = 0;
	while (word[i] != NULL)
	{
		free(word[i]);
		word[i] = NULL;
		i++;
	}
	if (word != NULL)
		free(word);
	word = NULL;
}
