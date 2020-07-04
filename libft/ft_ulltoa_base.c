/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:37:18 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/22 19:17:43 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define NULLTER 1

char		*ft_ulltoa_base(unsigned long long n, int base)
{
	int					i;
	char				*s;
	char				buf[200];
	char				*ret;

	s = "0123456789abcdef";
	if (base == 10)
		return (ft_lltoa(n));
	if (n == 0)
		return (ft_strdup("0"));
	ft_memset(buf, -1, 200);
	buf[199] = '\0';
	i = 198;
	while (n)
	{
		buf[i] = s[n % base];
		n /= base;
		i--;
	}
	if (!(ret = (char *)malloc(sizeof(char) * (200 - i))))
		return (0);
	i++;
	ret = ft_strcpy(ret, &(buf[i]));
	return (ret);
}
