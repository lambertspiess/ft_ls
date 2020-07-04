/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:13:22 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/19 13:58:52 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_free(void *p)
{
	int		has_been_freed;

	has_been_freed = 0;
	if (p)
	{
		free(p);
		p = NULL;
		has_been_freed = 1;
	}
	return (has_been_freed);
}
