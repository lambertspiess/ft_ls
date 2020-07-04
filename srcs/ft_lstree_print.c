/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstree_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:48:19 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/17 12:59:32 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_lprintutil(t_data *data, char *buf, t_lsformat wid,
					int i)
{
	i = 0;
	i = ft_putstr_buf((char *)(&(buf[0])), data->perms, wid.permwid, i);
	i = ft_putint_buf((char *)(&(buf[0])), data->hardlinks, wid.hardlnwid + 1,
			i);
	i = ft_putstrl_buf((char *)(&(buf[0])), data->ownername,
		wid.ownernamewid + 1, i);
	i = ft_putstrl_buf((char *)(&(buf[0])), data->ownergroup,
		wid.grpnamewid + 1, i);
	return (i);
}

static int		ft_lprintutil_smm(t_data *data, char *buf, t_lsformat wid,
					int i)
{
	char			*sp;

	sp = ft_malloc_memset(wid.major + wid.minor + 1, ' ');
	if (data->type != 2 && data->type != 6)
	{
		if (wid.minor != 0)
			i = ft_putstr_buf((char *)(&(buf[0])), sp, 0, i);
		i = ft_putlld_buf((char *)(&(buf[0])), data->filesize,
				wid.filesizewid, i);
	}
	else
	{
		i = ft_putint_buf((char *)(&(buf[0])), data->major, wid.major + 1, i);
		i = ft_putstr_buf((char *)(&(buf[0])), ",", 0, i);
		i = ft_putint_buf((char *)(&(buf[0])), data->minor, wid.minor, i);
	}
	ft_free(sp);
	return (i);
}
void			ft_lstree_lprint(t_data *data, t_lsops ops, t_lsformat wid)
{
	char			buf[9999];
	int				i;

	i = 0;
	i = ft_lprintutil(data, (char *)(&(buf[0])), wid, i);
	i = ft_lprintutil_smm(data, (char *)(&(buf[0])), wid, i);
	i = ft_putstr_buf((char *)(&(buf[0])), data->timestr, wid.timewid + 1, i);
	buf[i++] = ' ';
	i = ft_putstr_buf((char *)(&(buf[0])), data->name, 0, i);
	if (data->symlinkname)
	{
		i = ft_putstr_buf((char *)(&(buf[0])), " -> ", 0, i);
		i = ft_putstr_buf((char *)(&(buf[0])), data->symlinkname, 0, i);
	}
	i = ft_putstr_buf((char *)(&(buf[0])), "\n", 0, i);
	write(1, (char *)(&(buf[0])), i);
}

void			ft_lstree_print(t_lsnode *head, t_lsops ops,
					t_lsformat lsformat)
{
	if (head->data == NULL)
		return ;
	if (head->left)
	{
		ft_lstree_print(head->left, ops, lsformat);
	}
	if (head)
	{
		if (ops.l)
			ft_lstree_lprint(head->data, ops, lsformat);
		else
			ft_putstr_nl(head->data->name);
	}
	if (head->right)
	{
		ft_lstree_print(head->right, ops, lsformat);
	}
}
