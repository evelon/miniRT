/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:55:37 by jolim             #+#    #+#             */
/*   Updated: 2021/01/20 14:49:18 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int			ft_parse_pl(char **word)
{
	t_plane		*plane;
	int			n;

	n = ft_count_word(word);
	if (n != 4)
		perror_exit("Too many or few elements for Plane");
	if (!(plane = (t_plane *)malloc(sizeof(t_plane))))
		return (0);
	if (ft_num_type(word[1]) != FT_COL && ft_num_type(word[1]) != FT_VEC)
		perror_exit("First element of Plane has an invalid value");
	if (ft_num_type(word[2]) != FT_COL && ft_num_type(word[2]) != FT_VEC)
		perror_exit("Second element of Plane has an invalid value");
	if (ft_num_type(word[3]) != FT_COL)
		perror_exit("Third element of Plane has an invalid value");
	plane->point = ft_read_vec(word[1]);
	plane->ori_v = v_unit(ft_read_vec(word[2]));
	if (!is_valid_unit(plane->ori_v))
		perror_exit("Wrong value of normalized vector for Plane");
	plane->color = ft_read_color(word[3]);
	if (!is_valid_color(plane->color))
		perror_exit("Color value of Plane is not valid");
	ft_new_object(PLANE, plane)->object = plane;
	return (1);
}

static int	ft_parse_sp_type(char **word)
{
	if (ft_num_type(word[1]) != FT_COL && ft_num_type(word[1]) != FT_VEC)
		perror_exit("First element of Sphere has an invalid value");
	if (ft_num_type(word[2]) != FT_INT && ft_num_type(word[2]) != FT_DBL)
		perror_exit("Second element of Sphere has an invalid value");
	if (ft_num_type(word[3]) != FT_COL)
		perror_exit("Third element of Sphere has an invalid value");
	return (1);
}

int			ft_parse_sp(char **word)
{
	t_sphere	*sphere;
	int			n;

	n = ft_count_word(word);
	if (n != 4)
		perror_exit("Too many or few elements for Sphere");
	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (0);
	ft_parse_sp_type(word);
	sphere->center = ft_read_vec(word[1]);
	sphere->radius = ft_atof(word[2]) / 2;
	if (atoi < 0)
		perror_exit("Radius of a Sphere cannot be a negative value");
	sphere->color = ft_read_color(word[3]);
	if (!is_valid_color(sphere->color))
		perror_exit("Color value of Sphere is not valid");
	ft_new_object(SPHERE, sphere)->object = sphere;
	return (1);
}

static int	ft_parse_sq_type(char **word)
{
	if (ft_num_type(word[1]) != FT_COL && ft_num_type(word[1]) != FT_VEC)
		perror_exit("First element of Square has an invalid value");
	if (ft_num_type(word[2]) != FT_COL && ft_num_type(word[2]) != FT_VEC)
		perror_exit("Second element of Square has an invalid value");
	if (ft_num_type(word[3]) != FT_INT && ft_num_type(word[3]) != FT_DBL)
		perror_exit("Third element of Square has an invalid value");
	if (ft_num_type(word[4]) != FT_COL)
		perror_exit("Fourth element of Square has an invalid value");
	return (1);
}

int			ft_parse_sq(char **word)
{
	t_square	*square;
	int			n;

	n = ft_count_word(word);
	if (n != 5)
		perror_exit("Too many or few elements for Square");
	if (!(square = (t_square *)malloc(sizeof(t_square))))
		return (0);
	ft_parse_sq_type(word);
	square->center = ft_read_vec(word[1]);
	square->ori_v = v_unit(ft_read_vec(word[2]));
	if (!is_valid_unit(square->ori_v))
		perror_exit("Wrong value of normalized vector for Square");
	square->side_half = ft_atof(word[3]) / 2;
	if (square->side_half < 0)
		perror_exit("Side of a Square cannot have a negative value");
	square->color = ft_read_color(word[4]);
	if (!is_valid_color(square->color))
		perror_exit("Color value of Light is not valid");
	ft_new_object(SQUARE, square)->object = square;
	return (1);
}
