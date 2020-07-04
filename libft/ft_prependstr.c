/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prependstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:19:25 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/07 16:17:58 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_prependstr(char *src, char *prep)
{
	int		i;
	char	*ret;
	int		lensrc;
	int		lenprep;

	i = 0;
	lensrc = ft_istrlen(src);
	lenprep = ft_istrlen(prep);
	if (!(ret = malloc(sizeof(char) * lensrc + lenprep + 1)))
		return (NULL);
	ft_strncpy(ret, prep, lenprep);
	ft_strcpy(ret + lenprep, src);
	return (ret);
}
