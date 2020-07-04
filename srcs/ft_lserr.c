/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lserr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:14:09 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/14 13:41:47 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lsprinterr(char *path, char *filename, char *pathname)
{
	char		*s;
	char		buf[9999];
	int			i;

//	printf("path = |%s|, filename = |%s|, pathname = |%s|\n",
//		path, filename, pathname);
	s = strerror(errno);
	i = 0;
	i = ft_putstr_buf((char *)(&(buf[0])), "ft_ls: ", 0, i);
	if (ft_strequ(path, "."))
		i = ft_putstr_buf((char *)(&(buf[0])), filename, 0, i);
	else
		i = ft_putstr_buf((char *)(&(buf[0])), pathname, 0, i);
	i = ft_putstr_buf((char *)(&(buf[0])), ": ", 0, i);
	i = ft_putstr_buf((char *)(&(buf[0])), s, 0, i);
	ft_putstr_nl(buf);
}
