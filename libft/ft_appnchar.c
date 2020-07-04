/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:02:59 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/14 12:25:56 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**	Appends len chars at the end of a string
*/

#include "libft.h"

char		*ft_appnchar(char *src, char c, int len)
{
	int		i;
	int		lim;
	char	*ret;
	int		lensrc;

	i = 0;
	if (len <= 0)
		return (ft_strdup(src));
	lensrc = ft_istrlen(src);
	if (!(ret = malloc(sizeof(char) * lensrc + len + 1)))
		return (NULL);
	ft_strcpy(ret, src);
	i = lensrc;
	lim = lensrc + len;
	while (i < lensrc + len)
		ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}
