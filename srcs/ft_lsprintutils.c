/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsprintutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:17:30 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/14 17:00:52 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_putstr_buf(char *buf, char *s, int wid, int i)
{
	int				j;
	int				slen;

	slen = ft_istrlen(s);
	while (slen < wid)
	{
		buf[i] = ' ';
		slen++;
		i++;
	}
	j = 0;
	while (s[j])
	{
		buf[i] = s[j];
		i++;
		j++;
	}
	buf[i] = '\0';
	return (i);
}

int				ft_putstrl_buf(char *buf, char *s, int wid, int i)
{
	int				j;
	int				slen;

	buf[i++] = ' ';
	j = 0;
	while (s[j])
	{
		buf[i] = s[j];
		i++;
		j++;
	}
	slen = ft_istrlen(s);
	while (slen < wid)
	{
		buf[i] = ' ';
		slen++;
		i++;
	}
	buf[i] = '\0';
	return (i);
}

int				ft_putint_buf(char *buf, int nb, int wid, int idx)
{
	char			*s;
	int				ret;

	s = ft_itoa(nb);
	ret = ft_putstr_buf(buf, s, wid, idx);
	ft_free(s);
	return (ret);
}

int				ft_putlld_buf(char *buf, long long nb, int wid, int idx)
{
	char			*s;
	int				ret;

	s = ft_lltoa(nb);
	ret = ft_putstr_buf(buf, s, wid, idx);
	ft_free(s);
	return (ret);
}

void			ft_putstr_nl(char *s)
{
	int				i;
	char			buf[9999];

	i = 0;
	while (s[i] && i < 9998)
	{
		buf[i] = s[i];
		i++;
	}
	if (buf[i - 1] != '\n')
		buf[i++] = '\n';
	buf[i] = '\0';
	write(1, (char *)(&(buf[0])), i);
}
