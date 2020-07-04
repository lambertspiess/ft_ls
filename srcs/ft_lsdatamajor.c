/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsdatamajor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:34:05 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/14 15:34:08 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls_getmajorminor(struct stat buf, t_data **datap)
{
	(*datap)->major = major(buf.st_rdev);
	(*datap)->minor = minor(buf.st_rdev);
}
