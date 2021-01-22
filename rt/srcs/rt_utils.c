/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:38:13 by jolim             #+#    #+#             */
/*   Updated: 2021/01/17 21:45:41 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	set_hit(t_hit_point *hit, t_light_lst *light)
{
	t_vec	v_temp;

	hit->vec_light = v_unit(v_sub(light->source, hit->point));
	hit->vec_viewer = v_unit(v_sub(g_scene->cur_camera->pov, hit->point));
	v_temp = v_mul(hit->vec_normal, v_dot(hit->vec_light, hit->vec_normal));
	v_temp = v_sub(v_temp, hit->vec_light);
	hit->vec_reflection = v_unit(v_add(hit->vec_light, v_mul(v_temp, 2)));
	hit->vec_half = v_unit(v_add(hit->vec_light, hit->vec_viewer));
	return ;
}

t_vec	ray_point(t_ray *ray, double t)
{
	t_vec	point;

	point = v_add(ray->origin, v_mul(ray->direction, t));
	return (point);
}

double	min_positive(double a, double b)
{
	if (a > 0 && b < 0)
		return (a);
	if (a < 0 && b > 0)
		return (b);
	if (a < 0 && b < 0)
		return (0);
	if (a > b && b > 0)
		return (b);
	return (a);
}