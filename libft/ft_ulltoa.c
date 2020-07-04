/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:14:16 by lspiess           #+#    #+#             */
/*   Updated: 2019/06/18 20:17:50 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MINUS 1

unsigned int	ft_get_ullnbr_size(unsigned long long nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size + 1);
}

char			*ft_ulltoa(unsigned long long n)
{
	unsigned long long	nb;
	unsigned int		size;
	char				*s;
	unsigned int		i;

	nb = n;
	size = ft_get_llnbr_size(nb);
	if (!(s = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	s[size] = '\0';
	i = size - 1;
	while (nb >= 10)
	{
		s[i] = (char)(nb % 10 + '0');
		nb /= 10;
		i--;
	}
	s[i] = (char)(nb % 10 + '0');
	return (s);
}
