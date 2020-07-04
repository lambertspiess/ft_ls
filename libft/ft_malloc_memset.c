/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_memset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:16:07 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/14 16:50:12 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**	returns a null-terminated fresh string initialized to the
**	specified character. Size specified needs not include the null-term.
*/

#include "libft.h"

void		*ft_malloc_memset(size_t size, char c)
{
	void			*mem;
	void			*ptr;

	if (size <= 0 || !(mem = (void *)malloc(sizeof(char) * size)))
		return (NULL);
	ptr = mem;
	while (size-- > 0)
		*((char *)ptr++) = c;
	*((char *)ptr) = '\0';
	return ((void *)mem);
}
