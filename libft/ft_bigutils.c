/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:46:51 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/22 13:48:00 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_bigpowten(int exp)
{
	char	*powten;

	if (!(powten = malloc(sizeof(char) * (exp + 2))))
		return (NULL);
	ft_memset(powten, '0', exp + 1);
	powten[exp + 1] = '\0';
	powten[0] = '1';
	return (powten);
}

char			*ft_trim_res(char **pres)
{
	int		primlen;
	int		i;
	int		len;
	char	*trimmed;
	char	*res;

	if (*pres == NULL)
		return (NULL);
	primlen = ft_istrlen(*pres);
	res = *pres;
	i = 0;
	while (res[i] == '0' && (i < primlen - 1))
		i++;
	len = ft_istrlen(res) - i + 1;
	if (!(trimmed = malloc(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(trimmed, &(res[i]));
	free(res);
	return (trimmed);
}

void			ft_rightalign(char *s, int rightshift, int len)
{
	int		i;

	i = len;
	while (--i >= 0)
	{
		if (i - rightshift >= 0)
		{
			s[i] = s[i - rightshift];
			s[i - rightshift] = '0';
		}
	}
}

char			*ft_biginit(t_bigutil *n, char *str1, char *str2)
{
	char			*res;

	n->ls1 = ft_istrlen(str1);
	n->ls2 = ft_istrlen(str2);
	n->lsm = n->ls1 > n->ls2 ? n->ls1 + 1 : n->ls2 + 1;
	n->s1 = ft_malloc_memset(n->lsm + 1, '0');
	n->s2 = ft_malloc_memset(n->lsm + 1, '0');
	res = ft_malloc_memset(n->lsm, '0');
	res[n->lsm - 1] = '\0';
	ft_strncpy(n->s1, str1, n->ls1);
	ft_strncpy(n->s2, str2, n->ls2);
	ft_rightalign(n->s1, n->lsm - n->ls1, n->lsm);
	ft_rightalign(n->s2, n->lsm - n->ls2, n->lsm);
	n->lim1 = n->lsm - n->ls1;
	n->lim2 = n->lsm - n->ls2;
	n->i = n->lsm - 1;
	n->j = n->lsm - 1;
	n->k = n->lsm - 1;
	return (res);
}
