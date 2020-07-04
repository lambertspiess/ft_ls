/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appnstr_freesrc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 10:34:45 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/19 16:34:03 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**	Appends (in place) n bytes of a string at the end of another another,
**	and then null-terminates.
*/

#include "libft.h"

void		ft_appnstr_inplace(char **src, char *app, size_t len)
{
	int		i;
	char	*ret;
	int		lensrc;

	if (app == NULL || len == 0)
		return ;
	i = 0;
	lensrc = ft_istrlen(*src);
	if (!(ret = malloc(sizeof(char) * lensrc + len + 1)))
		return ;
	ft_strncpy(ret, *src, lensrc);
	ft_strncpy((ret + lensrc), app, len);
	ret[lensrc + len] = '\0';
	free(*src);
	*src = ret;
	return ;
}
