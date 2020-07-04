/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:50:59 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/22 14:33:14 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat_free(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	append;

	append = ft_strlen(src);
	i = 0;
	j = 0;
	if (src == NULL)
		return (ft_strlen(dst));
	while (dst[i] && size && i < size)
		i++;
	while (src[j] && size && i < size - 1)
		dst[i++] = src[j++];
	if (src)
		free(src);
	if (j != 0)
	{
		dst[i] = '\0';
		return (i - j + append);
	}
	return (i + append);
}
