/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsprintblocks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:58:24 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/14 16:10:48 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_getblcksize_rec(t_lsnode *head, long long *cp)
{
	if (head->left)
		ft_getblcksize_rec(head->left, cp);
	if (head->data->blcks != -1)
		*cp += head->data->blcks;
	if (head->right)
		ft_getblcksize_rec(head->right, cp);
}

void			ft_lsprintblocks(t_lsnode *root)
{
	long long		count;
	char			buf[100];
	int				i;

	count = 0;
	ft_getblcksize_rec(root, &count);
	i = 0;
	i = ft_putstr_buf((char *)(&(buf[0])), "total ", 0, i);
	i = ft_putlld_buf((char *)(&(buf[0])), count, 0, i);
	ft_putstr_nl(buf);
}
