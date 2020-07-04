/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:39:58 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/22 13:34:27 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
**	ft_add_numstr
**
** SYNOPSIS
**	ft_add_numstr(char *s1, char *s2);
**
** PARAMETERS
**	char *s1, char *s2	--	string representations of two positive integers
**
** DESCRIPTION
**	Performs an addition of two numbers represented as two valid strings of
**	digits. A valid string for the purpose of this function is a sequence of
**	strictly numerical chars followed by a null. If the strings are invalid
**	the behavior is undefined.
**
** RETURN VALUE
**	a (malloc'd) string representing the sum of the two numbers.
*/

static void		ft_free_bigaddvars(char **s1, char **s2, char **s3, char **s4)
{
	ft_free(*s1);
	ft_free(*s2);
	ft_free(*s3);
	ft_free(*s4);
}

static char		*ft_get_strsum(char *s1, char *s2, int maxlen)
{
	char		*rsum;
	char		*ret;
	int			i;
	int			carry;
	int			digitsum;

	if (!(rsum = (char *)malloc(sizeof(char) * maxlen + 1)))
		return (NULL);
	ft_bzero(rsum, maxlen + 1);
	i = 0;
	carry = 0;
	while (i < maxlen)
	{
		digitsum = ((s1[i] - '0') + (s2[i] - '0'));
		rsum[i] = ((digitsum + carry) % 10) + '0';
		carry = digitsum + carry > 9 ? 1 : 0;
		i++;
	}
	--i;
	while (rsum[i] == '0')
		--i;
	rsum[i + 1] = '\0';
	ret = ft_strrev(rsum);
	ft_free(rsum);
	return (ret);
}

char			*ft_bigadd(char *s1, char *s2)
{
	t_bigutil	n;
	char		*rs1;
	char		*rs2;
	char		*sum;

	n.ls1 = ft_strlen(s1);
	n.ls2 = ft_strlen(s2);
	n.k = n.ls1 >= n.ls2 ? n.ls1 + 1 : n.ls2 + 1;
	rs1 = ft_mmalloc(n.k + 1);
	rs2 = ft_mmalloc(n.k + 1);
	if (!rs1 || !rs2)
		return (NULL);
	rs1[n.k] = '\0';
	rs2[n.k] = '\0';
	ft_memset(rs1, '0', n.k);
	ft_memset(rs2, '0', n.k);
	(n.s1) = ft_strrev(s1);
	(n.s2) = ft_strrev(s2);
	ft_strncpy(rs1, (n.s1), n.ls1);
	ft_strncpy(rs2, (n.s2), n.ls2);
	sum = ft_get_strsum(rs1, rs2, n.k);
	ft_free_bigaddvars(&rs1, &rs2, &(n.s1), &(n.s2));
	return (sum);
}
