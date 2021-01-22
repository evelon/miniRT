/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manage_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:56:04 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 16:06:00 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_camera_lst	*ft_new_camera(void)
{
	t_camera_lst	*new;
	t_camera_lst	*temp;

	if (!(new = (t_camera_lst *)malloc(sizeof(t_camera_lst))))
		return (NULL);
	new->next = NULL;
	if (g_scene->camera_head == NULL)
		return (g_scene->camera_head = new);
	temp = g_scene->camera_head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return (new);
}

t_light_lst		*ft_new_light(void)
{
	t_light_lst	*new;
	t_light_lst	*temp;

	if (!(new = (t_light_lst *)malloc(sizeof(t_light_lst))))
		return (NULL);
	new->next = NULL;
	if (g_scene->light_head == NULL)
		return (g_scene->light_head = new);
	temp = g_scene->light_head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return (new);
}

t_object_lst	*ft_new_object(char type, void *object)
{
	t_object_lst	*new;
	t_object_lst	*temp;

	if (!(new = (t_object_lst *)malloc(sizeof(t_object_lst))))
		return (NULL);
	new->object = object;
	new->type = type;
	new->next = NULL;
	if (g_scene->object_head == NULL)
		return (g_scene->object_head = new);
	temp = g_scene->object_head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return (new);
}

void			init_camera(t_camera_lst *camera, \
		char *c_pov, char *c_unit, char *c_fov)
{
	t_vec	y_axis;
	t_vec	pov;
	t_vec	unit;
	double	fov;

	pov = ft_read_vec(c_pov);
	unit = v_unit(ft_read_vec(c_unit));
	fov = ft_atof(c_fov);
	y_axis = v_new(0.0, 1.0, 0.0);
	if (unit.x == 0 && unit.z == 0)
		unit.x += 0.001;
	camera->pov = pov;
	camera->width = v_mul(v_unit(v_crs(unit, y_axis)), fabs(2 * tan(fov / 2)));
	camera->height = v_div(v_mul(v_unit(v_crs(camera->width, unit)), \
			v_len(camera->width)), g_ratio);
	camera->lower_left = v_sub(v_add(pov, unit), \
			v_mul(v_add(camera->width, camera->height), 0.5));
	camera->next = NULL;
}
