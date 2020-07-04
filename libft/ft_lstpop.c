/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:19:04 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/17 23:00:49 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstpop(t_list **p_head, void (*del)(void *, size_t))
{
	t_list		*node;

	node = *p_head;
	*p_head = (*p_head)->next;
	ft_lstdelone(&node, del);
	return (*p_head);
}
