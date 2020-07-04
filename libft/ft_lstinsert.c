/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:12:42 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/16 01:25:21 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstinsert(t_list **head, void *cntnt, size_t cntnt_size)
{
	t_list		*node;

	node = ft_lstnew(cntnt, cntnt_size);
	if (node != NULL)
	{
		node->next = *head;
		*head = node;
	}
	return (node);
}
