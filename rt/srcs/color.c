/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:43:35 by jolim             #+#    #+#             */
/*   Updated: 2021/01/16 11:03:18 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_color			vec_to_color(t_vec vec)
{
	t_color	color;

	color.r = (unsigned char)(255.0 * vec.x);
	color.g = (unsigned char)(255.0 * vec.y);
	color.b = (unsigned char)(255.0 * vec.z);
	return (color);
}

t_vec			color_to_vec(t_color color)
{
	t_vec	vec;

	vec.x = (double)color.r / 255.0;
	vec.y = (double)color.g / 255.0;
	vec.z = (double)color.b / 255.0;
	return (vec);
}

unsigned int	color_to_int(t_color color)
{
	unsigned int	color_int;

	color_int = 0;
	color_int += (color.r << 16) | (color.g << 8) | color.b;
	return (color_int);
}
