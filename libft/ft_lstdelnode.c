/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:38:05 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/14 18:14:24 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_delnode(t_list *node)
{
	if (node->content)
	{
		free(node->content);
		node->content = NULL;
	}
	node->content_size = 0;
	free(node);
}

void			ft_lstdelnode(t_list **p_head, size_t index)
{
	t_list		*prev;
	t_list		*node;
	size_t		i;

	if (!(*p_head))
		return ;
	prev = *p_head;
	if (index == 0)
	{
		*p_head = (*p_head)->next;
		ft_delnode(prev);
		return ;
	}
	i = 0;
	while (++i < index && prev)
		prev = prev->next;
	if (!prev || !(prev->next))
		return ;
	node = prev->next;
	prev->next = prev->next->next;
	ft_delnode(node);
}
