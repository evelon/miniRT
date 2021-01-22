/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:47:57 by jolim             #+#    #+#             */
/*   Updated: 2020/10/10 15:15:54 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*copy_node(\
		t_list *target, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;

	if (!(new_node = ft_lstnew(f(target->content))))
		return (NULL);
	if (target->next != NULL)
	{
		if (!(new_node->next = copy_node(target->next, f, del)))
		{
			del(new_node->content);
			free(new_node);
			return (NULL);
		}
		return (new_node);
	}
	new_node->next = NULL;
	return (new_node);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;

	if (lst == NULL)
		return (NULL);
	if (!(copy = copy_node(lst, f, del)))
		return (NULL);
	return (copy);
}
