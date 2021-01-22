/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj_t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:22:49 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 17:22:51 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	ray_sphere_t(t_ray *ray, t_sphere *sphere)
{
	t_vec 	oc;
	double	a;
	double	b;
	double	c;
	double	t_value;

	oc = v_sub(ray->origin, sphere->center);
	a = v_dot(ray->direction, ray->direction);
	if (a == 0)
		return (__DBL_MAX__);
	b = 2.0 * v_dot(oc, ray->direction);
	c = v_dot(oc, oc) - sphere->radius * sphere->radius;
	if ((c = b * b - 4 * a * c) < 0.0)
		return (__DBL_MAX__);
	t_value = min_positive((-b - sqrt(c)) / (2.0 * a), \
			(-b + sqrt(c)) / (2.0 * a));
	if (t_value <= 0.0)
		return (__DBL_MAX__);
	return (t_value);
}

double	ray_plane_t(t_ray *ray, t_plane *plane)
{
	double	t_value;

	if ((v_dot(plane->ori_v, ray->direction) == 0))
		return (__DBL_MAX__);
	t_value = (v_dot(plane->point, plane->ori_v) - \
			v_dot(ray->origin, plane->ori_v)) / \
			v_dot(ray->direction, plane->ori_v);
	if (t_value <= 0.0)
		return (__DBL_MAX__);

	return (t_value);
}

double	ray_cylinder_t(t_ray *ray, t_cylinder *cylinder)
{
	double	a;
	double	b;
	double	c;
	double	t_value[2];
	double	d;

	ray_cylinder_quad(ray, cylinder, &a, &b, &c);
	if ((c = b * b - 4 * a * c) <= 0)
		return (__DBL_MAX__);
	if (a == 0)
		return (__DBL_MAX__);
	t_value[0] = (-b - sqrt(c)) / (2 * a);
	t_value[1] = (-b + sqrt(c)) / (2 * a);
	d = v_dot(v_sub(ray_point(ray, t_value[0]), cylinder->center), \
			cylinder->ori_v);
	if (d >= cylinder->height || d <= 0)
		t_value[0] = __DBL_MAX__;
	d = v_dot(v_sub(ray_point(ray, t_value[1]), cylinder->center), \
			cylinder->ori_v);
	if (d >= cylinder->height || d <= 0)
		t_value[1] = __DBL_MAX__;
	return (min_positive(min_positive(t_value[0], t_value[1]), \
			ray_cylinder_cap_t(ray, cylinder)));
}

double	ray_square_t(t_ray *ray, t_square *square)
{
	double	t_value;
	t_vec	axis;
	t_vec	point;
	double	d;

	t_value = ray_sq_plane_t(ray, square);
	if (t_value <= 0)
		return (__DBL_MAX__);
	point = ray_point(ray, t_value);
	if (square->ori_v.x == 0 && square->ori_v.z == 0)
		axis = v_new(0, 0, 1);
	else
		axis = v_crs(square->ori_v, v_new(0, 1, 0));
	d = v_dot(v_sub(point, square->center), axis) / v_len(axis);
	if (d > square->side_half || d < -square->side_half)
		t_value = __DBL_MAX__;
	axis = v_crs(square->ori_v, axis);
	d = v_dot(v_sub(point, square->center), axis) / v_len(axis);
	if (d > square->side_half || d < -square->side_half)
		t_value = __DBL_MAX__;
	return (t_value);
}

double	ray_triangle_t(t_ray *ray, t_triangle *tr)
{
	t_vec	edge[3];
	t_vec	to[3];
	t_vec	point;
	t_plane	plane;
	double	t_value;

	edge[0] = v_sub(tr->second, tr->first);
	edge[1] = v_sub(tr->third, tr->second);
	edge[2] = v_sub(tr->first, tr->third);
	plane.ori_v = v_unit(v_crs(edge[0], edge[1]));
	plane.point = tr->second;
	t_value = ray_plane_t(ray, &plane);
	if (t_value <= 0)
		return (__DBL_MAX__);
	point = ray_point(ray, t_value);
	to[0] = v_sub(point, tr->first);
	to[1] = v_sub(point, tr->second);
	to[2] = v_sub(point, tr->third);
	if (v_dot(plane.ori_v, v_crs(edge[0], to[0])) <= 0)
		return (__DBL_MAX__);
	if (v_dot(plane.ori_v, v_crs(edge[1], to[1])) <= 0)
		return (__DBL_MAX__);
	if (v_dot(plane.ori_v, v_crs(edge[2], to[2])) <= 0)
		return (__DBL_MAX__);
	return (t_value);
}
