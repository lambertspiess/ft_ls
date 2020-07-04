/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:41:28 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/22 13:53:04 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char static		*ft_notrim_strsum(char *s1, char *s2, int maxlen)
{
	char	*rsum;
	int		i;
	int		carry;
	int		digitsum;

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
	rsum[i + 1] = '\0';
	return (ft_strrev(rsum));
}

char			*ft_notrim_bigadd(char *s1, char *s2)
{
	t_bigutil	n;
	char		*rs1;
	char		*rs2;
	int			maxlen;
	char		*sum;

	n.ls1 = ft_strlen(s1);
	n.ls2 = ft_strlen(s2);
	maxlen = n.ls1;
	if (!(rs1 = (char *)malloc(sizeof(char) * maxlen + 1)) \
		|| !(rs2 = (char *)malloc(sizeof(char) * maxlen + 1)))
		return (NULL);
	rs1[maxlen] = '\0';
	rs2[maxlen] = '\0';
	ft_memset(rs1, '0', maxlen);
	ft_memset(rs2, '0', maxlen);
	ft_strncpy(rs1, ft_strrev(s1), n.ls1);
	ft_strncpy(rs2, ft_strrev(s2), n.ls2);
	sum = ft_notrim_strsum(rs1, rs2, maxlen);
	ft_frees(2, rs1, rs2);
	return (sum);
}

char			*ft_bigsub(char *str1, char *str2)
{
	t_bigutil	n;
	char		*res;

	n.swap = NULL;
	res = ft_biginit(&n, str1, str2);
	while (n.i >= 0)
	{
		n.top = n.s1[n.i] - '0';
		n.bot = n.s2[n.i] - '0';
		if (n.top - n.bot < 0)
		{
			n.swap = ft_notrim_bigadd(n.s2, ft_bigpowten(n.lsm - n.i));
			free(n.s2);
			n.s2 = n.swap;
			n.bot = n.s2[n.i] - '0';
			res[n.i] = (n.top + 10 - n.bot) + '0';
		}
		else
			res[n.i] = (n.top - n.bot) + '0';
		n.i--;
	}
	ft_frees(2, n.s1, n.s2);
	return (ft_trim_res(&res));
}

char			*ft_notrim_bigsub(char *str1, char *str2)
{
	t_bigutil	n;
	char		*res;

	n.swap = NULL;
	res = ft_biginit(&n, str1, str2);
	while (n.i >= 0)
	{
		n.top = n.s1[n.i] - '0';
		n.bot = n.s2[n.i] - '0';
		if (n.top - n.bot < 0)
		{
			n.swap = ft_notrim_bigadd(n.s2, ft_bigpowten(n.lsm - n.i));
			free(n.s2);
			n.s2 = n.swap;
			n.bot = n.s2[n.i] - '0';
			res[n.i] = (n.top + 10 - n.bot) + '0';
		}
		else
			res[n.i] = (n.top - n.bot) + '0';
		n.i--;
	}
	ft_frees(2, n.s1, n.s2);
	return (ft_trim_res(&res));
}
