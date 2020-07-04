/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opencurrentir_seekfile.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:16:52 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/16 16:35:37 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_lsfilenamedata_free(t_data *data)
{
	ft_free(data->name);
	ft_free(data->path);
	ft_free(data->pathname);
	ft_free(data->perms);
	ft_free(data->ownername);
	ft_free(data->ownergroup);
	ft_free(data->timestr);
	ft_free(data->symlinkname);
	ft_free(data->next);
}

int				ft_lsopencurrentdir_seekfile(t_lsdirdata *d, char *filename)
{
	d->dirp = opendir(".");
	while ((d->filp = readdir(d->dirp)))
	{
		if (ft_strequ(d->filp->d_name, filename))
			return (1);
	}
	return (0);
}

void			ft_ls_filename(t_lsdirdata *d, t_lsops ops,
					char *filename, char *path)
{
	t_data			*data;
	t_lsformat		lsformat;

	data = NULL;
	if (!(ops.l))
	{
		if (ft_strequ(path, "."))
			ft_putstr_nl(filename);
		else
			ft_putstr_nl(d->pathname);
		return ;
	}
	ft_ls_init_lsformat(&lsformat);
	ft_ls_get_filpdata(d->pathname, d->filp, &data);
	ft_call_statorlstat(d->filp->d_type, d->pathname, &(d->buf));
	ft_ls_get_statdata(d->buf, &lsformat, data, d->ops);
	ft_lstree_lprint(data, d->ops, lsformat);
	ft_lsfilenamedata_free(data);
	ft_free(data);
}
