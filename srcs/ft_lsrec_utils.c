/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsrec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:14:14 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/14 13:44:46 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_lsdata_free(t_data **datap)
{
	if (!(*datap))
		return ;
	ft_free((*datap)->name);
	ft_free((*datap)->path);
	ft_free((*datap)->pathname);
	ft_free((*datap)->perms);
	ft_free((*datap)->ownername);
	ft_free((*datap)->ownergroup);
	ft_free((*datap)->timestr);
	ft_free((*datap)->symlinkname);
	ft_free((*datap));
}

void			ft_ls_recursive(t_lsnode **headp, t_lsops ops,
					char **pathsofarp)
{
	if ((*headp)->left)
		ft_ls_recursive(&((*headp)->left), ops, pathsofarp);
	if ((*headp)->data->type == 4)
	{
		ops.isrec = 1;
		ops.isfirst = 0;
		ft_ls(ops, (*headp)->data->name, ft_strdup(*pathsofarp));
	}
	if ((*headp)->right)
		ft_ls_recursive(&((*headp)->right), ops, pathsofarp);
//FREEMEM TEST
	ft_lsdata_free(&((*headp)->data));
	ft_free((*headp));
}
