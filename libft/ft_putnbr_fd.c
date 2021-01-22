/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 05:01:13 by jolim             #+#    #+#             */
/*   Updated: 2020/10/13 11:02:40 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putdigit_re(int n, int fd)
{
	int	digit;

	if (n == 0)
		return ;
	digit = n % 10;
	if (digit < 0)
		digit = -1 * digit;
	digit += '0';
	putdigit_re(n / 10, fd);
	write(fd, &digit, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
		write(fd, "0", 1);
	putdigit_re(n, fd);
}
