/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepnstr_inplace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:49:03 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/08 11:53:38 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_prepnstr_inplace(char **src, char *prep, size_t len)
{
	int		i;
	char	*ret;
	int		lensrc;

	i = 0;
	lensrc = ft_istrlen(*src);
	if (!(ret = malloc(sizeof(char) * lensrc + len + 1)))
		return ;
	ft_strncpy(ret, prep, len);
	ft_strcpy(ret + len, *src);
	free(*src);
	*src = ret;
	return ;
}
