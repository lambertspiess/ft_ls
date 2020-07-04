/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_bzero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:46:14 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/06 11:46:16 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_malloc_bzero(size_t size)
{
	void			*mem;
	void			*ptr;

	if (!(mem = (void *)malloc(sizeof(char) * size)))
		return (NULL);
	ptr = mem;
	while (size-- > 0)
		*((char *)ptr++) = 0;
	return ((void *)mem);
}
