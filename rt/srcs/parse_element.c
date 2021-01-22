/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:03:00 by jolim             #+#    #+#             */
/*   Updated: 2021/01/16 11:03:16 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	ft_parse_resolution(char **word)
{
	int	n;

	n = ft_count_word(word);
	if (g_width != -1)
		perror_exit("cannot have more than one Resolution");
	if (n != 3)
		perror_exit("Too many or few elements for Resolution");
	if (ft_num_type(word[1]) != FT_INT || ft_num_type(word[2]) != FT_INT)
		perror_exit("Invalid elements for Resolution");
	if ((g_width = ft_atoi(word[1])) <= 0)
		perror_exit("Cannot set display width as negative number or zero");
	if ((g_height = ft_atoi(word[2])) <= 0)
		perror_exit("Cannot set display height as negative number or zero");
	g_ratio = (double)g_width / (double)g_height;
	return (1);
}

int	ft_parse_ambient(char **word)
{
	int			n;
	int			type;

	if (g_ambient != NULL)
		perror_exit("Ambient already set");
	if (!(g_ambient = (t_ambient *)malloc(sizeof(t_ambient))))
		return (0);
	n = ft_count_word(word);
	if (n != 3)
		perror_exit("Too many or few elements for Ambient");
	type = ft_num_type(word[1]);
	if (type != FT_INT && type != FT_DBL)
		perror_exit("First element for Ambient has an invalid value");
	type = ft_num_type(word[2]);
	if (type != FT_COL)
		perror_exit("Second element for Ambient has an invalid value");
	g_ambient->ratio = ft_atof(word[1]);
	if (g_ambient->ratio < 0.0 || g_ambient->ratio > 1.0)
		perror_exit("Wrong value for Ambient ratio");
	g_ambient->color = ft_read_color(word[2]);
	if (!is_valid_color(g_ambient->color))
		perror_exit("Ambient color value is not valid");
	return (1);
}

int	ft_parse_camera(char **word)
{
	t_camera_lst	*camera;
	int				type;
	int				n;

	camera = NULL;
	n = ft_count_word(word);
	if (n != 4)
		perror_exit("Too many or few elements for Camera");
	if (!(camera = ft_new_camera()))
		return (0);
	type = ft_num_type(word[1]);
	if (type != FT_COL && type != FT_VEC)
		perror_exit("First element for Camera has an invalid value");
	type = ft_num_type(word[2]);
	if (type != FT_COL && type != FT_VEC)
		perror_exit("Second element for Camera has an invalid value");
	type = ft_num_type(word[3]);
	if (type != FT_INT && type != FT_DBL)
		perror_exit("Third element for Camera has an invalid value");
	if (!is_valid_unit(ft_read_vec(word[2])))
		perror_exit("Wrong value of normalized vector for Camera");
	if (ft_atof(word[3]) < 0.0 || ft_atof(word[3]) > 180.0)
		perror_exit("Wrong value of FOV for Camera");
	init_camera(camera, word[1], word[2], word[3]);
	return (1);
}

int	ft_parse_light(char **word)
{
	t_light_lst	*light;
	int			type;
	int			n;

	n = ft_count_word(word);
	if (n != 4)
		perror_exit("Too many or less elemenets for Light");
	light = ft_new_light();
	type = ft_num_type(word[1]);
	if (type != FT_COL && type != FT_VEC)
		perror_exit("First element for Light has an invalid value");
	type = ft_num_type(word[2]);
	if (type != FT_INT && type != FT_DBL)
		perror_exit("Second element for Light has an invalid value");
	type = ft_num_type(word[3]);
	if (type != FT_COL && type != FT_VEC)
		perror_exit("Third element for Light has an invalid value");
	light->source = ft_read_vec(word[1]);
	light->brightness = ft_atof(word[2]);
	if (light->brightness < 0.0 || light->brightness > 1.0)
		perror_exit("Wrong value of brightness for Light");
	light->color = ft_read_color(word[3]);
	if (!is_valid_color(light->color))
		perror_exit("Color value of Light is not valid");
	return (1);
}
