/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepnchar_inplace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:48:35 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/19 12:54:54 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**	Prepends (in place) len chars c at the beginning of a string
*/

#include "libft.h"

void		ft_prepnchar_inplace(char **src, char c, int len)
{
	int		i;
	char	*ret;
	int		lensrc;

	if (len <= 0)
		return ;
	lensrc = ft_istrlen(*src);
	if (!(ret = malloc(sizeof(char) * lensrc + len + 1)))
		return ;
	i = 0;
	while (i < len)
		ret[i++] = c;
	ft_strcpy(ret + i, *src);
	free(*src);
	*src = ret;
	return ;
}
