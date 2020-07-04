/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsdata_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:36:20 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/16 15:12:56 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_lsdata_init(t_data **datap)
{
	(*datap)->perms = NULL;
	(*datap)->hardlinks = -1;
	(*datap)->ownername = NULL;
	(*datap)->ownergroup = NULL;
	(*datap)->filesize = -1;
	(*datap)->timeval = -1;
	(*datap)->blcks = -1;
	(*datap)->symlinkname = NULL;
	(*datap)->next = NULL;
	(*datap)->major = -1;
	(*datap)->minor = -1;
}

void			ft_ls_print_datavars(t_data *data, t_data **datap)
{
	printf("data (%p)", *datap);
	printf("name = %s, path = %s, next = %p, root = %p\n",
		(*datap)->name, (*datap)->path, (*datap)->next, (*datap)->root);
}

void			ft_lsdata_freelist(t_data *data)
{
	t_data		*head;
	t_data		*prev;

	if (!data)
		return ;
	data = data->root;
	head = data;
	while (head)
	{
		prev = head;
		ft_free(head->name);
		ft_free(head->path);
		ft_free(head->pathname);
		ft_free(head->perms);
		ft_free(head->ownername);
		ft_free(head->ownergroup);
		ft_free(head->timestr);
		ft_free(head->symlinkname);
		head = head->next;
		ft_free(prev);
	}
}

static void		ft_ls_get_perms(t_data *data, struct stat buf)
{
	data->perms = ft_mmalloc(11);
	data->perms[0] = S_ISDIR(buf.st_mode) ? 'd' : '-';
	data->perms[0] = S_ISCHR(buf.st_mode) ? 'c' : data->perms[0];
	data->perms[0] = S_ISBLK(buf.st_mode) ? 'b' : data->perms[0];
	data->perms[0] = S_ISLNK(buf.st_mode) ? 'l' : data->perms[0];
	data->perms[0] = S_ISSOCK(buf.st_mode) ? 's' : data->perms[0];
	data->perms[0] = S_ISFIFO(buf.st_mode) ? 'p' : data->perms[0];
	data->perms[1] = (buf.st_mode & S_IRUSR) ? 'r' : '-';
	data->perms[2] = (buf.st_mode & S_IWUSR) ? 'w' : '-';
	data->perms[3] = (buf.st_mode & S_IXUSR) ? 'x' : '-';
	data->perms[4] = (buf.st_mode & S_IRGRP) ? 'r' : '-';
	data->perms[5] = (buf.st_mode & S_IWGRP) ? 'w' : '-';
	data->perms[6] = (buf.st_mode & S_IXGRP) ? 'x' : '-';
	data->perms[7] = (buf.st_mode & S_IROTH) ? 'r' : '-';
	data->perms[8] = (buf.st_mode & S_IWOTH) ? 'w' : '-';
	data->perms[9] = (buf.st_mode & S_IXOTH) ? 'x' : '-';
	data->perms[10] = '\0';
}

static char		*ft_lsdata_readlink(char *pathname)
{
	char			*buf;

	buf = ft_malloc_memset(100, '\0');
	readlink(pathname, buf, 100);
	return (buf);
}

void			ft_ls_get_statdata(struct stat buf, t_lsformat *lsformat,
					t_data *data, t_lsops ops)
{
	struct passwd	*pwinfo;
	struct group	*grinfo;
	char			*swp;

	ft_ls_get_perms(data, buf);
	data->hardlinks = buf.st_nlink;//hardlinks for files, nb of files for dirs
	pwinfo = getpwuid(buf.st_uid);
	data->ownername = (pwinfo)? ft_strdup(pwinfo->pw_name): NULL;
	grinfo = getgrgid(buf.st_gid);
	data->ownergroup = (grinfo) ? ft_strdup(grinfo->gr_name) : NULL;
	data->filesize = buf.st_size;
	data->timeval = buf.st_mtime;
	swp = ft_strdup(ctime(&(buf.st_mtime)));
	data->timestr = ft_strndup(swp + 4, 12);
	data->blcks = buf.st_blocks;
	if (data->type == 10)
		data->symlinkname = ft_lsdata_readlink(data->pathname);
	if (data->type == 2 || data->type == 6)
		ft_ls_getmajorminor(buf, &data);
	if (ops.l)
		ft_ls_setcolumns(data, lsformat);
	ft_free(swp);
}
