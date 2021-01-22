/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:20:58 by jolim             #+#    #+#             */
/*   Updated: 2021/01/18 16:26:47 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vec		v_new(double x, double y, double z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec		v_sub(t_vec u, t_vec w)
{
	u.x -= w.x;
	u.y -= w.y;
	u.z -= w.z;
	return (u);
}

t_vec		v_add(t_vec u, t_vec w)
{
	u.x += w.x;
	u.y += w.y;
	u.z += w.z;
	return (u);
}

t_vec		v_mul(t_vec v, double t)
{
	v.x *= t;
	v.y *= t;
	v.z *= t;
	return (v);
}

t_vec		v_div(t_vec v, double t)
{
	v.x /= t;
	v.y /= t;
	v.z /= t;
	return (v);
}
