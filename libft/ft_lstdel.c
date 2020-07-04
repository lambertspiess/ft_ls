/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:04:53 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/08 19:32:38 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
		del((*alst)->content, (*alst)->content_size);
	if ((*alst)->next)
		ft_lstdel(&((*alst)->next), del);
	free(*alst);
	*alst = NULL;
}
