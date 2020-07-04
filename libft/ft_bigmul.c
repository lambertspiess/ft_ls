/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigmul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:43:14 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/22 13:38:17 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	We compute the addends one by one. The power of ten are tracked through the
**	indexation of addends. Any given addends is computed as if the multiplier
**	was the first one. Once computed the number will be shifted left the
**	appropriate number of times and padded with zeroes.
**
** RETURN VALUE
**	a malloc'd string representation of the result of the multiplication
*/

char			*ft_singlemul(t_bigutil n, int mul)
{
	char		*res;
	int			carry;

	if (!(res = malloc(n.lsm + 1)))
		return (NULL);
	ft_memset(res, '0', n.lsm);
	res[n.lsm] = '\0';
	carry = 0;
	while (n.j >= 0)
	{
		n.top = n.s1[n.j] - '0';
		res[n.j] = (((n.top * mul) + carry) % 10) + '0';
		carry = ((n.top * mul) + carry) / 10;
		n.j--;
	}
	return (res);
}

char			*ft_bigmul(char *str1, char *str2)
{
	t_bigutil	n;
	char		*res;
	char		*add;
	char		*sum;

	res = ft_strdup("0");
	ft_biginit_mul(&n, str1, str2);
	while (n.i >= n.lim2)
	{
		add = ft_singlemul(n, n.s2[n.i] - '0');
		ft_leftshift(&add, n.j - n.i);
		sum = ft_bigadd(res, add);
		free(res);
		res = sum;
		free(add);
		n.i--;
	}
	ft_frees(2, n.s1, n.s2);
	return (res);
}

char			*ft_bigmul_free(char *str1, char *str2, int f1, int f2)
{
	t_bigutil	n;
	char		*res;
	char		*add;
	char		*sum;

	res = ft_strdup("0");
	ft_biginit_mul(&n, str1, str2);
	while (n.i >= n.lim2)
	{
		add = ft_singlemul(n, n.s2[n.i] - '0');
		ft_leftshift(&add, n.j - n.i);
		sum = ft_bigadd(res, add);
		free(res);
		res = sum;
		free(add);
		n.i--;
	}
	ft_frees(2, n.s1, n.s2);
	if (f1)
		ft_free(str1);
	if (f2)
		ft_free(str2);
	return (res);
}
