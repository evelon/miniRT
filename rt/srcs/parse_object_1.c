/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:59:27 by jolim             #+#    #+#             */
/*   Updated: 2021/01/20 14:43:23 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	ft_parse_cy_type(char **word)
{
	int	type;

	type = ft_num_type(word[1]);
	if (type != FT_COL && type != FT_VEC)
		perror_exit("First element of Cylinder has an invalid value");
	type = ft_num_type(word[2]);
	if (type != FT_COL && type != FT_VEC)
		perror_exit("Second element of Cylinder has an invalid value");
	type = ft_num_type(word[3]);
	if (type != FT_INT && type != FT_DBL)
		perror_exit("Third element of Cylinder has an invalid value");
	type = ft_num_type(word[4]);
	if (type != FT_INT && type != FT_DBL)
		perror_exit("Fourth element of Cylinder has an invalid value");
	type = ft_num_type(word[5]);
	if (type != FT_COL)
		perror_exit("Fifth element of cylinder has an invalid value");
	return (1);
}

int			ft_parse_cy(char **word)
{
	t_cylinder	*cylinder;
	int			n;

	n = ft_count_word(word);
	if (n != 6)
		perror_exit("Too many or few elements for Cylinder");
	if (!(cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (0);
	ft_parse_cy_type(word);
	cylinder->center = ft_read_vec(word[1]);
	cylinder->ori_v = ft_read_vec(word[2]);
	if (!is_valid_unit(cylinder->ori_v))
		perror_exit("Wrong value of normalized vector for Cylinder");
	cylinder->ori_v = v_unit(cylinder->ori_v);
	cylinder->radius = ft_atof(word[3]) / 2;
	if (cylinder->radius < 0)
		perror_exit("Radius of a Cylinder cannot be a negative value");
	cylinder->height = ft_atof(word[4]);
	if (cylinder->height < 0)
		perror_exit("Height of a Cylinder cannot be a negative value");
	cylinder->color = ft_read_color(word[5]);
	if (!is_valid_color(cylinder->color))
		perror_exit("Color value of Cylinder is not valid");
	ft_new_object(CYLINDER, cylinder)->object = cylinder;
	return (1);
}

int			ft_parse_tr(char **word)
{
	t_triangle	*triangle;
	int			n;

	n = ft_count_word(word);
	if (n != 5)
		perror_exit("Too many or less elements for Triangle");
	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		return (0);
	if (ft_num_type(word[1]) != FT_COL && ft_num_type(word[1]) != FT_VEC)
		perror_exit("First element of Triangle has an invalid value");
	if (ft_num_type(word[2]) != FT_COL && ft_num_type(word[2]) != FT_VEC)
		perror_exit("Second element of Triangle has an invalid value");
	if (ft_num_type(word[3]) != FT_COL && ft_num_type(word[3]) != FT_VEC)
		perror_exit("Third element of Triangle has an invalid value");
	triangle->first = ft_read_vec(word[1]);
	triangle->second = ft_read_vec(word[2]);
	triangle->third = ft_read_vec(word[3]);
	triangle->color = ft_read_color(word[4]);
	if (!is_valid_color(triangle->color))
		perror_exit("Color value of Triangle is not valid");
	ft_new_object(TRIANGLE, triangle)->object = triangle;
	return (1);
}
