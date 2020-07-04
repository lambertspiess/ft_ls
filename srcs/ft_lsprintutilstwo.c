/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsprintutilstwo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:41:36 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/16 16:53:34 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_ls_parseprintpath(char *s)
{
	int				i;
	int				pathcount;

	i = 0;
	pathcount = 0;
	while (s[i])
	{
		if (s[i] == '/')
			pathcount++;
		i++;
	}
	return (pathcount);
}

void			ft_putstr_nlpath(char *s)
{
	int				i;
	char			buf[9999];

	i = 0;
	while (s[i] && i < 9998)
	{
		buf[i] = s[i];
		i++;
	}
	buf[i++] = ':';
	if (buf[i - 1] != '\n')
		buf[i++] = '\n';
	buf[i] = '\0';
	write(1, (char *)(&(buf[0])), i);
}
