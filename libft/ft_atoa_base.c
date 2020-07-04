/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:33:55 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/28 16:05:13 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
**	ft_atoa_base
**
** SYNOPSIS
**	char	*ft_atoa_base(char *s, int base);
**
** PARAMETERS
**	char *s1, char *s2	--	string representations of two positive integers
**
** DESCRIPTION
**	convert a string representation of a positive number from a given bases
**	(hex or lower) to another specified base (hex or lower)
**
** RETURN VALUE
**	string representation of the number in the specified base (non malloc'd)
*/

static char		*ft_sign_to_dec(char c)
{
	char			*base;
	char			*mbase;
	int				i;
	char			*ret;
	char			*to_free;

	base = ft_strdup("0123456789abcdef");
	mbase = ft_strdup("0123456789ABCDEF");
	i = 0;
	ret = NULL;
	while (base[i] && base[i] != c && mbase[i] != c)
		i++;
	if (i >= 10)
		ret = ft_mmalloc(3);
	else
		ret = ft_mmalloc(2);
	to_free = ft_itoa(i);
	ft_strcpy(ret, to_free);
	ft_frees(3, to_free, base, mbase);
	return (ret);
}

static void		ft_init_atoa_utils(t_bigutil *n, char *s, int base,
					char **sbase)
{
	n->s1 = NULL;
	n->s2 = NULL;
	n->s3 = NULL;
	n->i = ft_istrlen(s);
	n->j = 0;
	*sbase = ft_itoa(base);
}

char			*ft_atoa_basetodec(char *s, int base)
{
	t_bigutil		n;
	char			*ret;
	char			*sbase;
	char			*swp;

	ft_init_atoa_utils(&n, s, base, &sbase);
	ret = NULL;
	swp = NULL;
	while (--n.i >= 0)
	{
		n.s1 = ft_sign_to_dec(s[n.i]);
		n.s2 = ft_bigpow(sbase, n.j);
		n.s3 = ft_bigmul(n.s1, n.s2);
		swp = ret;
		if (n.j == 0)
			ret = ft_bigadd("0", n.s3);
		else
			ret = ft_bigadd(ret, n.s3);
		n.j++;
		ft_free(swp);
		ft_frees(3, n.s1, n.s2, n.s3);
	}
	ft_free(sbase);
	return (ret);
}
