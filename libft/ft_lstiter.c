/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:40:46 by jolim             #+#    #+#             */
/*   Updated: 2020/10/10 15:14:36 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	iterater(t_list *lst, void (*f)(void *))
{
	if (lst->content != NULL)
		f(lst->content);
	if (lst->next != NULL)
		iterater(lst->next, f);
	return ;
}

void		ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	iterater(lst, f);
	return ;
}
