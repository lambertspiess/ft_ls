/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:30:38 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/14 18:13:26 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int		strtrim_len(const char *s)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] && is_whitespace(s[i]))
		i++;
	while (s[i])
	{
		len++;
		i++;
	}
	i--;
	while (s[i] && is_whitespace(s[i]))
	{
		i--;
		len--;
	}
	return (len + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	if (!(s))
		return (NULL);
	len = strtrim_len(s);
	if (len <= 0)
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (size_t)len)))
		return (NULL);
	i = 0;
	while (s[i] && is_whitespace(s[i]))
		i++;
	j = 0;
	while (j < (len - 1))
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
