/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsformat_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:27:16 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/14 17:05:54 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls_init_lsformat(t_lsformat *f)
{
	f->permwid = 0;
	f->hardlnwid = 0;
	f->ownernamewid = 0;
	f->grpnamewid = 0;
	f->filesizewid = 0;
	f->timewid = 0;
	f->major = 0;
	f->minor = 0;
}

/*
** todo : Should verify before updating colwidths that if the file is
** invisible, the -a option is present
*/

void			ft_ls_setcolumns(t_data *data, t_lsformat *lsformat)
{
	int				len;

	if ((len = ft_istrlen(data->perms)) > lsformat->permwid)
		lsformat->permwid = len;
	if ((len = ft_nblen(data->hardlinks)) > lsformat->hardlnwid)
		lsformat->hardlnwid = len;
	if ((len = ft_istrlen(data->ownername)) > lsformat->ownernamewid)
		lsformat->ownernamewid = len;
	if ((len = ft_istrlen(data->ownergroup)) > lsformat->grpnamewid)
		lsformat->grpnamewid = len;
	if ((len = ft_nblen(data->filesize)) > lsformat->filesizewid)
		lsformat->filesizewid = len;
	if ((len = ft_istrlen(data->timestr)) > lsformat->timewid)
		lsformat->timewid = len;
	if (data->type == 2 || data->type == 6)
	{
		if ((len = ft_nblen(data->major)) > lsformat->major)
			lsformat->major = len;
		if ((len = ft_nblen(data->minor)) > lsformat->minor)
			lsformat->minor = len;
	}
	return ;
}
