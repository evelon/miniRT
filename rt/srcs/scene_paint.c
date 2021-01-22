/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:02:16 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 18:16:21 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static t_ray	*new_ray_cam(int i, int j)
{
	t_camera_lst	*cam;
	t_ray			*ray;
	double			u;
	double			w;

	if (!(ray = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	cam = g_scene->cur_camera;
	u = ((g_width - i) / (double)g_width) - 0.001;
	w = ((g_height - j) / (double)g_height) - 0.001;
	ray->origin = cam->pov;
	ray->direction = v_unit(v_sub(v_add(cam->lower_left, \
			v_add(v_mul(cam->width, u), v_mul(cam->height, w))), cam->pov));
	return (ray);
}

static t_vec	trace_ray(t_ray *ray)
{
	t_hit_point	*hit;
	t_vec		sp_df_color;
	t_vec		v_color_sum;
	t_light_lst	*light;

	hit = hit_object(ray);
	if (hit->t_value == __DBL_MAX__)
		return (v_new(0.5, 0.7, 1.0));
	sp_df_color = v_new(0, 0, 0);
	light = g_scene->light_head;
	while (light != NULL)
	{
		set_hit(hit, light);
		if (!ray_shadow(hit, light))
			sp_df_color = v_add(v_add(sp_df_color, \
v_mul(color_to_vec(light->color), hit_specular(hit, light))), \
v_add(sp_df_color, hit_diffuse(hit, light)));
		light = light->next;
	}
	v_color_sum = v_max(v_blend(v_mul(color_to_vec(g_ambient->color), \
			g_ambient->ratio), hit->v_color), sp_df_color);
	free(hit);
	return (v_cap(v_color_sum));
}

static t_color	paint_pixel(int i, int j)
{
	t_ray	*ray;
	t_vec	v_color;
	double	x;
	double	y;

	x = 0.25 * cos(30) - 0.25 * sin(30);
	y = 0.25 * cos(30) + 0.25 * sin(30);
	ray = new_ray_cam((double)i + x, (double)j + y);
	v_color = trace_ray(ray);
	free(ray);
	ray = new_ray_cam((double)i - x, (double)j - y);
	v_color = v_add(v_color, trace_ray(ray));
	free(ray);
	ray = new_ray_cam((double)i - y, (double)j + x);
	v_color = v_add(v_color, trace_ray(ray));
	free(ray);
	ray = new_ray_cam((double)i + y, (double)j - x);
	free(ray);
	v_color = v_add(v_color, trace_ray(ray));
	v_color = v_div(v_color, 4);
	return (vec_to_color(v_color));
}

void			scene_paint(t_image *image)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_width)
	{
		j = 0;
		while (j < g_height)
		{
			image->data_addr[i + j * image->size_line / 4] = \
					color_to_int(paint_pixel(i, j));
			j++;
		}
		i++;
	}
}
