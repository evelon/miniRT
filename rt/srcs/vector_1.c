/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:22:26 by jolim             #+#    #+#             */
/*   Updated: 2021/01/18 16:26:46 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double		v_len(t_vec v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double		v_dot(t_vec u, t_vec w)
{
	return (u.x * w.x + u.y * w.y + u.z * w.z);
}

t_vec		v_crs(t_vec u, t_vec w)
{
	t_vec	v;

	v.x = u.y * w.z - u.z * w.y;
	v.y = u.z * w.x - u.x * w.z;
	v.z = u.x * w.y - u.y * u.x;
	return (v);
}

t_vec		v_unit(t_vec v)
{
	return (v_div(v, v_len(v)));
}
