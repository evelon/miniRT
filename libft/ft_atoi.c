/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:14:42 by jolim             #+#    #+#             */
/*   Updated: 2021/01/06 16:41:20 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int	p;
	int	num;
	int	sign;

	if (*str == '\0')
		return (0);
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == 0)
		str++;
	p = 0;
	num = 0;
	while (*(str + p) <= '9' && *(str + p) >= '0')
	{
		num *= 10;
		num += (*(str + p) - '0') * sign;
		p++;
	}
	return (num);
}
