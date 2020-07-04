/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendnstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:16:38 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/19 16:34:52 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_appnstr(char *src, char *app, size_t len)
{
	int		i;
	char	*ret;
	int		lensrc;

	i = 0;
	lensrc = ft_istrlen(src);
	if (!(ret = malloc(sizeof(char) * lensrc + len + 1)))
		return (NULL);
	ft_strncpy(ret, src, lensrc);
	ft_strncpy(ret + lensrc, app, len);
	ret[lensrc + len] = '\0';
	return (ret);
}
