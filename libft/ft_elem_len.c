/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:50:54 by lspiess           #+#    #+#             */
/*   Updated: 2019/04/19 14:59:21 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_elem_len(char const *s, int begin, char delim)
{
	size_t elemlen;

	elemlen = 0;
	while (s[begin] && s[begin] != delim)
	{
		elemlen++;
		begin++;
	}
	return (elemlen);
}
