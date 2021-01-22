/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:39:46 by jolim             #+#    #+#             */
/*   Updated: 2021/01/18 16:26:45 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	v_cos(t_vec u, t_vec w)
{
	return (v_dot(u, w) / (v_len(u) * v_len(w)));
}

double	v_sin(t_vec u, t_vec w)
{
	return (v_len(v_crs(u, w)) / (v_len(u) * v_len(w)));
}

t_vec	v_blend(t_vec u, t_vec w)
{
	u.x = u.x * w.x;
	u.y = u.y * w.y;
	u.z = u.z * w.z;
	return (u);
}

t_vec	v_max(t_vec u, t_vec w)
{
	if (u.x < w.x)
		u.x = w.x;
	if (u.y < w.y)
		u.y = w.y;
	if (u.z < w.z)
		u.z = w.z;
	return (u);
}

t_vec	v_cap(t_vec v)
{
	if (v.x > 1.0)
		v.x = 1.0;
	if (v.y > 1.0)
		v.y = 1.0;
	if (v.z > 1.0)
		v.z = 1.0;
	return (v);
}
