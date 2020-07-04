/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:37:07 by lspiess           #+#    #+#             */
/*   Updated: 2019/04/18 17:33:23 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		(*node).content = NULL;
		(*node).content_size = 0;
		(*node).next = NULL;
		return (node);
	}
	(*node).content_size = content_size;
	if (!(node->content = (void *)malloc(content_size)))
		return (NULL);
	node->content = ft_memcpy(node->content, content, content_size);
	node->next = NULL;
	return (node);
}
