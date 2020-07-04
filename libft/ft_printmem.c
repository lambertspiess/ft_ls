/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:12:01 by lspiess           #+#    #+#             */
/*   Updated: 2019/06/10 14:30:01 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
**		ft_printmem_ltor
**		ft_printmem_rtol
**
** SYNOPSIS
**		ft_printmem_ltor(void *data, size_t data_size);
**		ft_printmem_rtol(void *data, size_t data_size);
**
** PARAMETERS
**		void *data		 --	a pointer to the region of memory to print
**		size_t data_size --	the size of that region of memory (in bytes)
**
** DESCRIPTION
**		print the binary of bytes from left to right (ltor)
**		or right to left (rtol)
**		Each bit of each byte is printed by evaluating an AND bitwise
**		operation between the pointed byte and a shifting mask.
**		If comparison evaluates to 1, print '1', else print '0'.
*/

#define MASK 1

void	ft_printmem_ltor(void *data, size_t data_size)
{
	unsigned char	*bytes;
	unsigned char	bit;
	size_t			i;
	size_t			j;
	size_t			k;

	bytes = (unsigned char *)(data);
	i = 0;
	k = 0;
	while (i < data_size)
	{
		j = 0;
		while (j < 8)
		{
			bit = (unsigned char)(bytes[k] & (MASK << (7 - j)));
			ft_putchar((bit ? '1' : '0'));
			++j;
		}
		k++;
		++i;
		if (i < data_size)
			ft_putchar(' ');
	}
	return ;
}

void	ft_printmem_rtol(void *data, size_t data_size)
{
	unsigned char	*bytes;
	unsigned char	bit;
	size_t			i;
	size_t			j;
	size_t			k;

	bytes = (unsigned char *)(data);
	i = 0;
	k = data_size - 1;
	while (i < data_size)
	{
		j = 0;
		while (j < 8)
		{
			bit = (unsigned char)(bytes[k] & (MASK << (7 - j)));
			ft_putchar((bit ? '1' : '0'));
			++j;
		}
		k--;
		++i;
		if (i < data_size)
			ft_putchar(' ');
	}
	return ;
}
