/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigsup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:39:12 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/22 13:39:37 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	These utilities are use to do comparisons on big integers.
**
** RETURN VALUES
**	1 for true, 0 for false, 2 for strictly equal.
*/

static int	ft_bigcompare(char *s1, char *s2, int type)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] - s2[i] != 0)
		{
			if (s1[i] - s2[i] > 0)
				return (type == 1 ? 1 : 0);
			if (s1[i] - s2[i] < 0)
				return (type == 1 ? 0 : 1);
		}
		i++;
	}
	return (2);
}

char		*ft_trimzeroes(char *s, int len)
{
	int		i;

	i = 0;
	while (s[i] == '0' && i < len)
		i++;
	return (ft_strdup(s + i));
}

int			ft_isbiggerthan(char *s1, char *s2)
{
	t_bigutil	n;
	char		*ts1;
	char		*ts2;
	int			ret;

	if ((s1[0] == '-' && s2[0] != '-') || (s1[0] != '-' && s2[0] == '-'))
		return ((s1[0] == '-' ? 0 : 1));
	s1 = (s1[0] == '-' || s1[0] == '+') ? s1++ : s1;
	s2 = (s2[0] == '-' || s1[0] == '+') ? s2++ : s2;
	n.ls1 = ft_strlen(s1);
	n.ls2 = ft_strlen(s2);
	ts1 = ft_trimzeroes(s1, n.ls1);
	n.ls1 = ft_istrlen(ts1);
	ts2 = ft_trimzeroes(s2, n.ls2);
	n.ls2 = ft_istrlen(ts2);
	if (n.ls1 > n.ls2)
		ret = 1;
	else if (n.ls1 < n.ls2)
		ret = 0;
	else
		ret = ft_bigcompare(ts1, ts2, 1);
	ft_frees(2, ts1, ts2);
	return (ret);
}

int			ft_issmallerthan(char *s1, char *s2)
{
	t_bigutil	n;
	char		*ts1;
	char		*ts2;
	int			ret;

	if ((s1[0] == '-' && s2[0] != '-') || (s1[0] != '-' && s2[0] == '-'))
		return ((s1[0] == '-' ? 1 : 0));
	s1 = (s1[0] == '-' || s1[0] == '+') ? s1++ : s1;
	s2 = (s2[0] == '-' || s1[0] == '+') ? s2++ : s2;
	n.ls1 = ft_strlen(s1);
	n.ls2 = ft_strlen(s2);
	ts1 = ft_trimzeroes(s1, n.ls1);
	n.ls1 = ft_istrlen(ts1);
	ts2 = ft_trimzeroes(s2, n.ls2);
	n.ls2 = ft_istrlen(ts2);
	if (n.ls1 > n.ls2)
		ret = 1;
	else if (n.ls1 < n.ls2)
		ret = 0;
	else
		ret = ft_bigcompare(ts1, ts2, 1);
	ft_frees(2, ts1, ts2);
	return (ret);
}
