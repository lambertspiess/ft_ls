/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsnode_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:31:30 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/13 20:28:52 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls_nodinit(t_lsnode **nodep)
{
	t_lsnode		*node;

	node = ft_mmalloc(sizeof(t_lsnode));
	node->data = NULL;
	node->left = NULL;
	node->right = NULL;
	node->branchlen = 0;
	*nodep = node;
}

void			ft_ls_nodset(t_lsnode *node, t_lsnode *left, t_lsnode *right,
					t_data *data)
{
	node->left = left;
	node->right = right;
	node->data = data;
}
