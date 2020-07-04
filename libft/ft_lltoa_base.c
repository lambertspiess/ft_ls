/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:37:18 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/22 18:07:22 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define NULLTER 1

char		*ft_lltoa_base(long long n, int base)
{
	unsigned long long	nb;
	int					i;
	char				*s;
	char				buf[100];
	char				*ret;

	s = "0123456789abcdef";
	if (base == 10)
		return (ft_lltoa(n));
	if (n == 0)
		return (ft_strdup("0"));
	nb = (n < 0 ? (unsigned long long)(-n) : (unsigned long long)n);
	ft_memset(buf, -1, 100);
	buf[99] = '\0';
	i = 98;
	while (n)
	{
		buf[i] = s[n % base];
		n /= base;
		i--;
	}
	ret = ft_mmalloc(100 - i);
	++i;
	ret = ft_strcpy(ret, &(buf[i]));
	return (ret);
}
