/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:44:25 by jolim             #+#    #+#             */
/*   Updated: 2021/01/16 11:03:12 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int			is_valid_color(t_color c)
{
	if (c.r < 0 || c.r > 255)
		return (0);
	if (c.g < 0 || c.g > 255)
		return (0);
	if (c.b < 0 || c.b > 255)
		return (0);
	return (1);
}

t_color		ft_read_color(char *str)
{
	t_color	c;

	c.r = ft_atoi(str);
	while (*str != ',')
		str++;
	str++;
	c.g = ft_atoi(str);
	while (*str != ',')
		str++;
	str++;
	c.b = ft_atoi(str);
	return (c);
}

t_vec		ft_read_vec(char *str)
{
	t_vec v;

	v.x = ft_atof(str);
	while (*str != ',')
		str++;
	str++;
	v.y = ft_atof(str);
	while (*str != ',')
		str++;
	str++;
	v.z = ft_atof(str);
	return (v);
}

static int	is_int_dbl(char **str)
{
	char	*tmp;

	if (**str == '+' || **str == '-')
		(*str)++;
	tmp = *str;
	while (**str <= '9' && **str >= '0')
		(*str)++;
	if (tmp == *str)
		return (FT_NOT);
	if (**str == '\0' || **str == ',' || **str == ' ')
		return (FT_INT);
	if (**str != '.')
		return (FT_NOT);
	(*str)++;
	tmp = *str;
	while (**str <= '9' && **str >= '0')
		(*str)++;
	if (tmp == *str)
		return (FT_NOT);
	if (**str == '\0' || **str == ',' || **str == ' ')
		return (FT_DBL);
	return (FT_NOT);
}

int			ft_num_type(char *str)
{
	int	type1;
	int	type2;
	int	type3;

	if ((type1 = is_int_dbl(&str)) == FT_NOT)
		return (FT_NOT);
	if (*str == '\0' || *str == ' ')
		return (type1);
	str++;
	if ((type2 = is_int_dbl(&str)) == FT_NOT)
		return (FT_NOT);
	if (*(str++) != ',')
		return (FT_NOT);
	if ((type3 = is_int_dbl(&str)) == FT_NOT)
		return (FT_NOT);
	if (*str == '\0' || *str == ' ')
	{
		if (type1 == FT_INT && type2 == type1 && type3 == type1)
			return (FT_COL);
		if (type1 == FT_DBL || type2 == FT_DBL || type3 == FT_DBL)
			return (FT_VEC);
	}
	return (FT_NOT);
}
