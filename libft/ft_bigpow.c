/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigpow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:23:28 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/28 12:25:06 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION
**	Returns a malloc'd string representing s to the power of pow.
*/

char			*ft_bigpow(char *s, int pow)
{
	int			dp;
	char		*ms;
	char		*ret;

	if (pow == 0)
		return (ft_strdup("1"));
	dp = pow / 2;
	ms = ft_strdup(s);
	if (pow >= 2)
	{
		if (pow % 2 == 1)
		{
			ret = (ft_bigmul_free(ft_bigmul_free(ft_bigpow(ms, dp), \
					ft_bigpow(ms, dp), 1, 1), ms, 1, 1));
			return (ret);
		}
		else if (pow % 2 == 0)
		{
			ret = (ft_bigmul_free(ft_bigpow(ms, dp), ft_bigpow(ms, dp), \
						1, 1));
			free(ms);
			return (ret);
		}
	}
	return (ms);
}
