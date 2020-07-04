/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appstr_inplace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:57:51 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/19 16:33:43 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**	Appends (in place) a string at the end of another another,
**	and then null-terminates.
*/

#include "libft.h"

void		ft_appstr_inplace(char **src, char *app)
{
	int		i;
	char	*ret;
	int		lensrc;
	int		len;

	if (app == NULL)
		return ;
	i = 0;
	lensrc = ft_istrlen(*src);
	len = ft_istrlen(app);
	if (!(ret = malloc(sizeof(char) * lensrc + len + 1)))
		return ;
	ft_strncpy(ret, *src, lensrc);
	ft_strcpy((ret + lensrc), app);
	free(*src);
	*src = ret;
	return ;
}
