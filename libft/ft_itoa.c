/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 02:31:18 by jolim             #+#    #+#             */
/*   Updated: 2020/10/10 15:26:48 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_scale(int n)
{
	int	scale;

	scale = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		scale++;
	}
	return (scale);
}

static char	get_digit(int i, int scale)
{
	int	n;
	int	tenpower;

	n = 1;
	tenpower = 1;
	while (n < scale)
	{
		tenpower *= 10;
		n++;
	}
	i /= tenpower;
	i %= 10;
	if (i < 0)
		i *= -1;
	return (i + '0');
}

static int	write_num(int i, int scale, char *num)
{
	int	ind;

	ind = 0;
	while (scale != 0)
	{
		num[ind++] = get_digit(i, scale);
		scale--;
	}
	num[ind] = '\0';
	return (1);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		scale;

	scale = get_scale(n);
	if (n < 0)
	{
		if (!(str = malloc((scale + 2) * sizeof(char))))
			return (NULL);
		*str = '-';
		write_num(n, scale, str + 1);
	}
	else
	{
		if (!(str = malloc((scale + 1) * sizeof(char))))
			return (NULL);
		write_num(n, scale, str);
	}
	return (str);
}
