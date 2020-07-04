/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:35:55 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/14 17:59:24 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	elemcnt(char const *s, char c)
{
	int		i;
	size_t	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static size_t	ft_elemlen(char const *s, size_t begin, char delim)
{
	size_t	elemlen;

	elemlen = 0;
	while (s[begin] && s[begin] != delim)
	{
		elemlen++;
		begin++;
	}
	return (elemlen);
}

static char		*ft_malloc_and_get_word(char const *s, char c, size_t len)
{
	char	*word;
	int		i;

	if (!(word = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**list;
	size_t	i;
	size_t	k;
	size_t	elemlen;

	if (!s || !(list = (char **)malloc(sizeof(char *) * (elemcnt(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			elemlen = ft_elemlen(s, i, c);
			if (!(list[k] = ft_malloc_and_get_word(s + i, c, elemlen)))
			{
				free(list);
				return (NULL);
			}
			i += ft_strlen(list[k++]) - 1;
		}
		i++;
	}
	list[k++] = 0;
	return (list);
}
