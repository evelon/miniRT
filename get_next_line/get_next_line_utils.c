/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:50:08 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 17:29:26 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		put_line(char *s, char **line, int len)
{
	int	i;

	if (!(*line = (char *)malloc((len + 1) + sizeof(char))))
		return (0);
	i = 0;
	while (i < len)
	{
		(*line)[i] = s[i];
		i++;
	}
	(*line)[i] = '\0';
	return (1);
}

char	*str_cut(char *s, int len)
{
	char	*new;
	int		new_len;
	int		i;

	new_len = ft_strlen(s) - len - 1;
	if (!(new = (char *)malloc((new_len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < new_len)
	{
		new[i] = s[len + 1 + i];
		i++;
	}
	new[i] = '\0';
	free(s);
	return (new);
}

char	*str_cat(char *s1, char *s2, int len2)
{
	int		len1;
	char	*new;
	int		i;

	len1 = ft_strlen(s1);
	if (!(new = (char *)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		new[len1 + i] = s2[i];
		i++;
	}
	new[len1 + len2] = '\0';
	free(s1);
	return (new);
}

int		nl_finder(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n')
	{
		if (str[len] == '\0')
			return (-1);
		len++;
	}
	return (len);
}
