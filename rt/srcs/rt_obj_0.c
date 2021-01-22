/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:37:50 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 17:57:55 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	ray_cylinder_quad(t_ray *ray, t_cylinder *cylinder, t_vec *a)
{
	t_vec	v;
	t_vec	w;
	t_vec	h;

	v = v_unit(ray->direction);
	w = v_sub(ray->origin, cylinder->center);
	h = cylinder->ori_v;
	a->x = v_dot(v, v) - pow(v_dot(v, h), 2);
	a->y = 2 * (v_dot(v, w) - v_dot(v, h) * v_dot(w, h));
	a->z = v_dot(w, w) - pow(v_dot(w, h), 2) - pow(cylinder->radius, 2);
	return (1);
}

double	ray_sq_plane_t(t_ray *ray, t_square *square)
{
	t_plane	plane;

	plane.ori_v = square->ori_v;
	plane.point = square->center;
	return (ray_plane_t(ray, &plane));
}

double	ray_cylinder_cap_t(t_ray *ray, t_cylinder *cylinder)
{
	t_plane	plane;
	double	t_value[2];

	plane.ori_v = cylinder->ori_v;
	plane.point = v_add(cylinder->center, v_mul(cylinder->ori_v, \
			cylinder->height));
	t_value[0] = ray_plane_t(ray, &plane);
	if (v_len(v_sub(ray_point(ray, t_value[0]), plane.point)) > \
			cylinder->radius)
		t_value[0] = __DBL_MAX__;
	plane.point = v_add(cylinder->center, v_mul(cylinder->ori_v, \
			0));
	t_value[1] = ray_plane_t(ray, &plane);
	if (v_len(v_sub(ray_point(ray, t_value[1]), plane.point)) > \
			cylinder->radius)
		t_value[1] = __DBL_MAX__;
	return (min_positive(t_value[0], t_value[1]));
}
