/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:51:22 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 14:18:57 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static double		shadow_t(t_ray *shadow_ray, t_object_lst *obj)
{
	if (obj->type == SPHERE)
		return (ray_sphere_t(shadow_ray, (t_sphere *)obj->object));
	if (obj->type == PLANE)
		return (ray_plane_t(shadow_ray, (t_plane *)obj->object));
	if (obj->type == SQUARE)
		return (ray_square_t(shadow_ray, (t_square *)obj->object));
	if (obj->type == CYLINDER)
		return (ray_cylinder_t(shadow_ray, (t_cylinder *)obj->object));
	if (obj->type == TRIANGLE)
		return (ray_triangle_t(shadow_ray, (t_triangle *)obj->object));
	return (__DBL_MAX__);
}

int					ray_shadow(t_hit_point *hit, t_light_lst *light)
{
	double			t_shadow;
	t_ray			s_ray;
	t_object_lst	*obj;

	s_ray.origin = hit->point;
	s_ray.direction = hit->vec_light;
	if (v_dot(hit->vec_normal, s_ray.direction) <= 0)
		return (1);
	t_shadow = __DBL_MAX__;
	obj = g_scene->object_head;
	while (obj != NULL)
	{
		if (obj->object != hit->object)
		{
			t_shadow = shadow_t(&s_ray, obj);
			if (t_shadow > 0 && t_shadow <= \
					v_len(v_sub(light->source, hit->point)) + 0.0001)
				return (2);
		}
		obj = obj->next;
	}
	return (0);
}

static t_hit_point	*ray_object_type(t_ray *ray, t_object_lst *obj)
{
	if (obj->type == SPHERE)
		return (ray_sphere(ray, (t_sphere *)obj->object));
	if (obj->type == PLANE)
		return (ray_plane(ray, (t_plane *)obj->object));
	if (obj->type == SQUARE)
		return (ray_square(ray, (t_square *)obj->object));
	if (obj->type == CYLINDER)
		return (ray_cylinder(ray, (t_cylinder *)obj->object));
	if (obj->type == TRIANGLE)
		return (ray_triangle(ray, (t_triangle *)obj->object));
	return (NULL);
}

t_hit_point			*hit_object(t_ray *ray)
{
	t_object_lst	*obj;
	t_hit_point		*hit;
	t_hit_point		*temp;

	obj = g_scene->object_head;
	if (!(hit = (t_hit_point *)malloc(sizeof(t_hit_point))))
		return (NULL);
	hit->t_value = __DBL_MAX__;
	temp = NULL;
	while (obj != NULL)
	{
		temp = ray_object_type(ray, obj);
		if (temp != NULL)
		{
			if (hit->t_value > temp->t_value)
			{
				free(hit);
				hit = temp;
			}
		}
		obj = obj->next;
	}
	return (hit);
}
