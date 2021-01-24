/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:54:22 by jolim             #+#    #+#             */
/*   Updated: 2021/01/24 16:44:56 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		perror_exit(char *err)
{
	write(1, "Error\n", 6);
	perror(err);
	exit(EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int		save_check(char *flag)
{
	int	len;

	len = ft_strlen(flag);
	if (len == 6 && !ft_strncmp(flag, "--save", 6))
		return (1);
	return (perror_exit("Wrong flag"));
}

int		ex_check(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len >= 3 && !ft_strncmp(&filename[len - 3], ".rt", 4))
		return (1);
	return (perror_exit("Wrong file name"));
}

double	dbl_max(double u, double w)
{
	if (u > w)
		return (u);
	return (w);
}
