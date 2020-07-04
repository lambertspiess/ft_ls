/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepnchar_inplace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:48:35 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/20 11:23:44 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**	Prepends len chars c at the beginning of a string
*/

#include "libft.h"

char		*ft_prepnchar(char *src, char c, int len)
{
	int			i;
	int			j;
	char		*ret;
	int			retlen;

	if (len <= 0)
		return (ft_strdup(src));
	retlen = ft_istrlen(src) + len;
	ret = ft_mmalloc(retlen);
	i = 0;
	while (i < len)
		ret[i++] = c;
	j = 0;
	while (i < retlen)
		ret[i++] = src[j++];
	ret[i] = '\0';
	return (ret);
}
