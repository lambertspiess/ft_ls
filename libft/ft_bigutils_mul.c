/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigutils_mul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:34:52 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/22 13:42:09 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_leftshift(char **ps, int lshifts)
{
	int		i;
	int		lim;
	char	*s;

	s = *ps;
	if (!lshifts)
		return ;
	i = 0;
	lim = 0;
	while (s[lim])
		lim++;
	while (i < lim)
	{
		if (i + lshifts < lim)
			s[i] = s[i + lshifts];
		else
			s[i] = '0';
		i++;
	}
	return ;
}

char			*ft_biginit_mul(t_bigutil *n, char *str1, char *str2)
{
	n->ls1 = ft_istrlen(str1);
	n->ls2 = ft_istrlen(str2);
	n->lsm = n->ls1 + n->ls2 + 1;
	n->s1 = ft_mmalloc(n->lsm + 1);
	n->s2 = ft_mmalloc(n->lsm + 1);
	ft_memset(n->s1, '0', n->lsm);
	ft_memset(n->s2, '0', n->lsm);
	n->s1[n->lsm] = '\0';
	n->s2[n->lsm] = '\0';
	ft_strncpy(n->s1, str1, n->ls1);
	ft_strncpy(n->s2, str2, n->ls2);
	ft_rightalign(n->s1, n->lsm - n->ls1, n->lsm);
	ft_rightalign(n->s2, n->lsm - n->ls2, n->lsm);
	n->lim1 = n->lsm - n->ls1;
	n->lim2 = n->lsm - n->ls2;
	n->i = n->lsm - 1;
	n->j = n->lsm - 1;
	n->k = n->lsm - 1;
	return (NULL);
}
