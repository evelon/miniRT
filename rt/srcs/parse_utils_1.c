/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:17:50 by jolim             #+#    #+#             */
/*   Updated: 2021/01/16 11:03:11 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int				ft_count_word(char **word)
{
	int	i;

	if (word == NULL || *word == NULL || **word == '\0')
		return (0);
	i = 0;
	while (word[i])
		i++;
	return (i);
}

static int		ft_atoi_int(char **str)
{
	int	num;

	num = 0;
	while (**str <= '9' && **str >= '0')
	{
		num *= 10;
		num += **str - '0';
		(*str)++;
	}
	return (num);
}

static int		ft_is_valid_f(char *str)
{
	char	*tmp;

	if (*str == '+' || *str == '-')
		str++;
	if (*str == '0' && *(str + 1) != '.')
	{
		if (*(str + 1) == ',' || *(str + 1) == ' ' || *(str + 1) == '\0')
			return (FT_INT);
		return (FT_NOT);
	}
	tmp = str;
	while (*str <= '9' && *str >= '0')
		str++;
	if (tmp == str)
		return (FT_NOT);
	if (*str != '.')
		return (FT_INT);
	tmp = ++str;
	while (*str <= '9' && *str >= '0')
		str++;
	if (tmp == str)
		return (FT_NOT);
	return (FT_DBL);
}

static double	ft_atof_frac(char *str)
{
	int		num;
	int		scale;
	double	num_d;

	num = 0;
	scale = 0;
	while (*str <= '9' && *str >= '0')
	{
		num *= 10;
		num += *str - '0';
		str++;
		scale++;
	}
	num_d = (double)num;
	while (scale > 0)
	{
		num_d /= 10;
		scale--;
	}
	return (num_d);
}

double			ft_atof(char *str)
{
	int		v;
	int		sign;
	double	num;

	v = ft_is_valid_f(str);
	if (v == 0)
		return (NAN);
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	num = (double)ft_atoi_int(&str);
	if (v == 2)
		num += ft_atof_frac(++str);
	num *= sign;
	return (num);
}
