/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstree_freetree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:36:31 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/07 18:31:55 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Frees the binary tree
*/

void			ft_lstree_freetree(t_lsnode *node)
{
	if (node->left)
		ft_lstree_freetree(node->left);
	if (node->right)
		ft_lstree_freetree(node->right);
	ft_free(node);
}
