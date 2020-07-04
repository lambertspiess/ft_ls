/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstree_addnode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:38:19 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/17 14:02:15 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_ls_nodecreate(t_lsnode *head, t_data *newdata,
					int direction, int branchlen)
{
	t_lsnode		*new;

	ft_ls_nodinit(&new);
	if (direction == 1)
	{
		head->left = new;
		new->data = newdata;
		new->branchlen = branchlen;
	}
	else if (direction == 2)
	{
		head->right = new;
		new->data = newdata;
		new->branchlen = branchlen;
	}
}

/*
**	select the binary path depending on the options of ls. Can be either
**	timestamp value or ascii order
*/

static int		ft_ls_tree_pickpath(t_lsnode *ahead, t_data *newdata,
					t_lsops ops)
{
	int				direction;

	int				strcmpret;
	direction = 0;
	if (!(ops.t))
	{
		if ((strcmpret = ft_strcmp(newdata->name, ahead->data->name) < 0))
			direction = (ops.r) ? 2 : 1;
		else
			direction = (ops.r) ? 1 : 2;
	}
	else
	{
		if (newdata->timeval > ahead->data->timeval)
		{
			direction = (ops.r) ? 2 : 1;
		}
		else
		{
			direction = (ops.r) ? 1 : 2;
		}
	}
	return (direction);
}

/*
**	brings the head pointer to the insertion node, increment the height
**	counter, and return the side where the node should be inserted
*/

static int		ft_ls_browsetree(int *branchlenp, t_data *newdata, t_lsops ops,
					t_lsnode **phead)
{
	t_lsnode		*ahead;
	int			direction;

	*branchlenp = 0;
	direction = 0;
	ahead = *phead;
	while (ahead)
	{
		*phead = ahead;
		direction = ft_ls_tree_pickpath(ahead, newdata, ops);
		if (direction == 1)
		{
			ahead = ahead->left;
		}
		else if (direction == 2)
		{
			ahead = ahead->right;
		}
		*branchlenp += 1;
	}
	return (direction);
}

/*
**	add a node to the binary search tree, makes sure it stays AVL
*/

void			ft_ls_addnode(t_lsnode *root, t_data *newdata, t_lsops ops)
{
	t_lsnode		*head;
	int				branchlen;
	int				direction;

	if (root->data == NULL)
	{
		root->data = newdata;
		root->branchlen = 0;
		return ;
	}
	head = root;
	direction = ft_ls_browsetree(&branchlen, newdata, ops, &head);
	ft_ls_nodecreate(head, newdata, direction, branchlen);
}
