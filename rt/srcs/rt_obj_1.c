/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:56:01 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 17:35:57 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	distance_ray_point(t_vec point_a, t_vec origin, t_vec direction)
{
	t_vec	temp;

	temp = v_crs(v_sub(point_a, origin), direction);
	return (v_len(temp) / v_len(direction));
}

double	distance_ray_ray(t_ray *line1, t_ray *line2)
{
	t_vec	pq;
	t_vec	crs;
	double	d;

	pq = v_sub(line1->origin, line2->origin);
	crs = v_crs(line1->direction, line2->direction);
	d = v_dot(pq, crs) / v_len(crs);
	if (d < 0)
		return (-d);
	return (d);
}

t_vec	foot_point_ray(t_vec point_a, t_vec origin, t_vec direction)
{
	return (v_add(origin, v_mul(v_unit(direction), \
			v_dot(v_sub(point_a, origin), v_unit(direction)))));
}

double	distance_points(t_vec p1, t_vec p2)
{
	return (v_len(v_sub(p1, p2)));
}
