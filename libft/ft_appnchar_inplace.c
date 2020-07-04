/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appnchar_inplace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:55:14 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/13 11:56:42 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**	Appends (in place) len chars at the end of a string
*/

#include "libft.h"

void		ft_appnchar_inplace(char **src, char c, int len)
{
	int		i;
	int		lim;
	char	*ret;
	int		lensrc;

	i = 0;
	if (len <= 0)
		return ;
	lensrc = ft_istrlen(*src);
	if (!(ret = malloc(sizeof(char) * lensrc + len + 1)))
		return ;
	ft_strcpy(ret, *src);
	i = lensrc;
	lim = lensrc + len;
	while (i < lensrc + len)
		ret[i++] = c;
	ret[i] = '\0';
	free(*src);
	*src = ret;
	return ;
}
