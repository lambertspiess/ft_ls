/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:11:48 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/17 13:02:24 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls_printpath(char *path, char *filename, t_lsops ops)
{
	int				pathlen;
	int				filelen;
	char			*buf;
	int				i;
	int				pathcount;

	pathlen = ft_istrlen(path);
	filelen = ft_istrlen(filename);
//	printf("ops.manyargs = %d, ops.isrec = %d\n", ops.manyargs, ops.isrec);
	if (ops.manyargs == 0 && ops.isrec == 0)
		return ;
	if (!(ops.isfirst) || ops.isrec)
		write(1, "\n", 1);
	buf = ft_ls_appendpaths(path, filename);
	i = 0;
	while (buf[i] == '/')
		i++;
	if (!(ops.rec) && (pathcount = ft_ls_parseprintpath(buf + i)) > 0)
		i += 2;
	else if (i > 0)
		i--;
	ft_putstr_nlpath(buf + i);
	ft_free(buf);
}

char			*ft_ls_appendpaths(char *pathsofar, char *filename)
{
	int				i;
	int				j;
	int				lens1;
	int				lens2;
	char			*newpath;

	lens1 = ft_istrlen(pathsofar);
	lens2 = ft_istrlen(filename);
	newpath = ft_mmalloc(lens1 + lens2 + 2);
	i = 0;
	while (pathsofar[i])
	{
		newpath[i] = pathsofar[i];
			i++;
	}
	newpath[i++] = '/';
	j = 0;
	while (filename[j])
		newpath[i++] = filename[j++];
	newpath[i] = '\0';
	return (newpath);
}

char			*ft_lsrec_apppaths(char *path, char *filename)
{
	char			*ret;

//	if (path[0] == '.' && filename[0] == '.')
	if (!(ft_strcmp(path, ".")) && !(ft_strcmp(filename, ".")))
		ret = ft_strdup(".");
	else
	{
		ret = ft_ls_appendpaths(path, filename);
//		printf("recppath = |%s|\n", ret);
	}
	return (ret);
}

/*
** Initializes d->pathname and d->dirp.
** On error, free *pathp and d->pathname. Returns 1 on success.
*/

int				ft_ls_init_dirp(t_lsdirdata *d, char **pathp, char *filename,
					t_lsnode **nodep)
{
	ft_ls_nodinit(nodep);
	d->pathname = ft_ls_appendpaths(*pathp, filename);
	d->dirp = opendir(d->pathname);
	if (d->dirp == NULL)
	{
		if (ft_lsopencurrentdir_seekfile(d, filename) == 1)
			ft_ls_filename(d, d->ops, filename, *pathp);
		else
			ft_lsprinterr(*pathp, filename, d->pathname);
		ft_free(d->pathname);
		ft_free(*pathp);
		ft_free(*nodep);
		if (d->dirp != NULL)
			closedir(d->dirp);
		return (-1);
	}
	ft_ls_printpath(*pathp, filename, d->ops);
	d->recpath = ft_lsrec_apppaths(*pathp, filename);
	return (1);
}

void			ft_ls_rec_or_free(t_lsops ops, t_lsnode **rootp,
					t_data **datap, t_lsdirdata *d)
{
	if (ops.rec && (*rootp)->data != NULL)
		ft_ls_recursive(rootp, ops, &(d->recpath));
	else
	{
		ft_lstree_freetree(*rootp);
		ft_lsdata_freelist(*datap);
	}
	ft_free(d->recpath);
}
