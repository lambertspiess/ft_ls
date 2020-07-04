/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prependnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:51:49 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/08 11:53:17 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_prependnstr(char *src, char *prep, size_t len)
{
	int		i;
	char	*ret;
	int		lensrc;

	i = 0;
	lensrc = ft_istrlen(src);
	if (!(ret = malloc(sizeof(char) * lensrc + len + 1)))
		return (NULL);
	ft_strncpy(ret, prep, len);
	ft_strcpy(ret + len, src);
	return (ret);
}
