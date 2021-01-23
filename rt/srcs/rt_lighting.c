/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lighting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:34:17 by jolim             #+#    #+#             */
/*   Updated: 2021/01/23 11:49:02 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	hit_specular(t_hit_point *hit, t_light_lst *light)
{
	double	intensity;

	intensity = v_dot(hit->vec_normal, hit->vec_half);
	if (intensity < 0)
		return (0);
	intensity = pow(intensity, 20);
	intensity = intensity * light->brightness;
	return (intensity);
}

t_vec	hit_diffuse(t_hit_point *hit, t_light_lst *light)
{
	double	intensity;
	t_vec	v_color;

	intensity = v_cos(hit->vec_light, hit->vec_normal);
	if (intensity < 0)
		intensity = 0;
	intensity = intensity * light->brightness;
	v_color = v_blend(hit->v_color, v_mul(color_to_vec(light->color), \
			intensity));
	return (v_color);
}
