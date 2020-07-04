/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:24:51 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/17 13:02:04 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
-R option : lists the contents of the current dir  by ascii order. If there are
dirs inside, after call ft_ls on them by ascii order.
first field is perms.
second is nb of hard links for files, nb of files inside for dirs (including . and ..)
third is owner name, fourth is owner group
fifth is file size
sixth is time of last modif
*/

/*
 * gotta implement :
 * - recursion (find a way to list the dirs and recursively call ls on them)
 * - binary tree rotations
 * - colum updating when -l (ft_lsformat)
 * - reverse flag (ft_lstree_print)
 */

#include "ft_ls.h"

static void		ft_ls_closedirp_freed_freepath(t_lsdirdata *d, char **pathp)
{
	closedir(d->dirp);
	ft_free(d->pathname);
	ft_free(*pathp);
}

void			ft_call_statorlstat(uint8_t type, char *pathname,
						struct stat *bufp)
{
	if (type == 10)
		lstat(pathname, bufp);
	else
		stat(pathname, bufp);
}

/*
** Mallocs and sets the t_data struct to default values, and stores the type,
** name and path of the file from the dirent struct in t_data.
*/

void			ft_ls_get_filpdata(char *path, struct dirent *filp,
					t_data **datap)
{
//	printf("*datap = %p\n", *datap);
	if (*datap == NULL)
	{
		*datap = ft_mmalloc(sizeof(t_data));
		(*datap)->root = *datap;
	}
	else
	{
		(*datap)->next = ft_mmalloc(sizeof(t_data));
		(*datap)->next->root = (*datap)->root;
		(*datap) = (*datap)->next;
	}
	(*datap)->name = ft_strdup(filp->d_name);
	(*datap)->path = ft_strdup(path);
	(*datap)->type = filp->d_type;
	(*datap)->pathname = ft_ls_appendpaths(path, (*datap)->name);
	ft_lsdata_init(datap);
}

/*
** Gets information about (char *)filename by calling opendir. Then iteratively
** call readdir on the files, storing data about those in the t_data linked
** list. In the same loop, if one of those files is of type dir, store its
** name in another linked list that shall be used for recursive calls.
*/

void			ft_ls(t_lsops ops, char *filename, char *path)
{
	t_lsdirdata		d;
	t_data			*data;
	t_lsformat		lsformat;
	t_lsnode		*root;

//	ft_ls_printpath(path, filename, ops);
	data = NULL;
	d.ops = ops;
	ft_ls_init_lsformat(&lsformat);
	if (ft_ls_init_dirp(&d, &path, filename, &root) == -1)
		return ;
	while ((d.filp = readdir(d.dirp)))
	{
		if (((d.filp)->d_name)[0] == '.' && ops.a == 0)
			continue ;
		ft_ls_get_filpdata(d.pathname, d.filp, &data);
		ft_call_statorlstat((d.filp)->d_type, data->pathname, &(d.buf));
		ft_ls_get_statdata(d.buf, &lsformat, data, ops);
		ft_ls_addnode(root, data, ops);
	}
	ft_ls_closedirp_freed_freepath(&d, &path);
	if (ops.l && root->data != NULL)
		ft_lsprintblocks(root);
	ft_lstree_print(root, ops, lsformat);
	ft_ls_rec_or_free(ops, &root, &data, &d);
}
