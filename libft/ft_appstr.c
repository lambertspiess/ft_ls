/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:54:43 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/09 12:56:08 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**	Appends n bytes of a string at the end of another another,
**	and then null-terminates.
*/

#include "libft.h"

char		*ft_appstr(char *src, char *app)
{
	int		i;
	char	*ret;
	int		lensrc;
	int		lenapp;

	i = 0;
	lensrc = ft_istrlen(src);
	lenapp = ft_istrlen(app);
	if (!(ret = malloc(sizeof(char) * lensrc + lenapp + 1)))
		return (NULL);
	ft_strncpy(ret, src, lensrc);
	ft_strcpy(ret + lensrc, app);
	return (ret);
}
