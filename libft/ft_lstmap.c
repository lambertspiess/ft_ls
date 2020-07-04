/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:46:28 by lspiess           #+#    #+#             */
/*   Updated: 2019/04/18 15:07:49 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*node;

	if (!(lst))
		return (NULL);
	else
	{
		node = f(lst);
		if (lst->next)
			node->next = ft_lstmap(lst->next, f);
		else
			node->next = NULL;
	}
	return (node);
}
