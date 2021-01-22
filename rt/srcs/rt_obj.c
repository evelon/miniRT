/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:25:47 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 14:08:43 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_hit_point	*ray_sphere(t_ray *ray, t_sphere *sphere)
{
	t_hit_point	*hit;

	if (!(hit = (t_hit_point *)malloc(sizeof(t_hit_point))))
		return (NULL);
	hit->object = sphere;
	hit->t_value = ray_sphere_t(ray, sphere);
	hit->point = ray_point(ray, hit->t_value);
	hit->vec_normal = v_unit(v_sub(hit->point, sphere->center));
	if (v_dot(hit->vec_normal, ray->direction) > 0)
		hit->vec_normal = v_mul(hit->vec_normal, -1);
	hit->v_color = color_to_vec(sphere->color);
	return (hit);
}

t_hit_point	*ray_plane(t_ray *ray, t_plane *plane)
{
	t_hit_point	*hit;

	if (!(hit = (t_hit_point *)malloc(sizeof(t_hit_point))))
		return (NULL);
	hit->object = plane;
	hit->t_value = ray_plane_t(ray, plane);
	hit->point = ray_point(ray, hit->t_value);
	hit->vec_normal = v_unit(plane->ori_v);
	if (v_dot(hit->vec_normal, ray->direction) > 0)
		hit->vec_normal = v_mul(hit->vec_normal, -1);
	hit->v_color = color_to_vec(plane->color);
	return (hit);
}

t_hit_point	*ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_hit_point	*hit;

	if (!(hit = (t_hit_point *)malloc(sizeof(t_hit_point))))
		return (NULL);
	hit->object = cylinder;
	hit->t_value = ray_cylinder_t(ray, cylinder);
	hit->point = ray_point(ray, hit->t_value);
	hit->vec_normal = v_unit(v_sub(v_sub(hit->point, cylinder->center), \
			v_mul(cylinder->ori_v, v_dot(cylinder->ori_v, v_sub(hit->point, \
			cylinder->center)))));
	if (hit->t_value == ray_cylinder_cap_t(ray, cylinder))
		hit->vec_normal = cylinder->ori_v;
	if (v_dot(hit->vec_normal, ray->direction) > 0)
		hit->vec_normal = v_mul(hit->vec_normal, -1);
	hit->v_color = color_to_vec(cylinder->color);
	return (hit);
}

t_hit_point	*ray_square(t_ray *ray, t_square *square)
{
	t_hit_point	*hit;

	if (!(hit = (t_hit_point *)malloc(sizeof(t_hit_point))))
		return (NULL);
	hit->object = square;
	hit->t_value = ray_square_t(ray, square);
	hit->point = ray_point(ray, hit->t_value);
	hit->vec_normal = v_unit(square->ori_v);
	if (v_dot(hit->vec_normal, ray->direction) > 0)
		hit->vec_normal = v_mul(hit->vec_normal, -1);
	hit->v_color = color_to_vec(square->color);
	return (hit);
}

t_hit_point	*ray_triangle(t_ray *ray, t_triangle *triangle)
{
	t_hit_point	*hit;
	t_vec		edge[2];

	if (!(hit = (t_hit_point *)malloc(sizeof(t_hit_point))))
		return (NULL);
	hit->object = triangle;
	hit->t_value = ray_triangle_t(ray, triangle);
	hit->point = ray_point(ray, hit->t_value);
	edge[0] = v_sub(triangle->second, triangle->first);
	edge[1] = v_sub(triangle->third, triangle->second);
	hit->vec_normal = v_unit(v_crs(edge[0], edge[1]));
	if (v_dot(hit->vec_normal, ray->direction) > 0)
		hit->vec_normal = v_mul(hit->vec_normal, -1);
	hit->v_color = color_to_vec(triangle->color);
	return (hit);
}
