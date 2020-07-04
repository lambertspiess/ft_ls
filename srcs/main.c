/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:52:20 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/14 13:59:28 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_init_ops(t_lsops *ops)
{
	ops->one = 0;
	ops->rec = 0;
	ops->r = 0;
	ops->l = 0;
	ops->a = 0;
	ops->t = 0;
	ops->err = 0;
	ops->errchar = 0;
}

static void		ft_get_ops(t_lsops *ops, char *s)
{
	int			i;

	i = 1;
	while (s[i])
	{
		if (s[i] == '1')
			ops->one = 1;
		else if (s[i] == 'R')
			ops->rec = 1;
		else if (s[i] == 'r')
			ops->r = 1;
		else if (s[i] == 'l')
			ops->l = 1;
		else if (s[i] == 'a')
			ops->a = 1;
		else if (s[i] == 't')
			ops->t = 1;
		else
		{
			ops->err = 1;
			ops->errchar = s[i];
			break;
		}
		i++;
	}
}

/*
 * (TO DO) 
** Parses the command line arg for the presence of a potential PATH.
** Mallocs *pathp with the PATH if present or "." is absent.
*/

static void		ft_extract_pathandname(char *s, char **pathp, char **namep)
{
	int				i;
	int				arglen;

	arglen = ft_istrlen(s);
	if (s[0] == '/' && arglen == 1)
	{
		(*pathp) = ft_strdup("");
		(*namep) = ft_strdup("/");
	}
	else if (!(ft_strchr(s, '/')))
	{
		(*pathp) = ft_strdup(".");
		(*namep) = ft_strdup(s);
	}
	else
	{
		i = arglen;
		while (i >= 0 && s[i] != '/')
			i--;
		(*namep) = ft_strdup(s + i + 1);
		i = (i == 0) ? 1 : i;
		(*pathp) = ft_strndup(s, i);
	}
}

int				main(int ac, char **av)
{
	t_lsops		ops;
	int			i;
	char		*path;
	char		*name;

	path = NULL;
	name = NULL;
	ft_init_ops(&ops);
	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] != '\0' && !(ops.err))
		ft_get_ops(&ops, av[i++]);
	ops.isrec = 0;
	ops.manyargs = (ac - i > 1) ? 1 : 0;
	ops.isfirst = 1;
	if (i == ac)
		ft_ls(ops, ".", ft_strdup("."));
	else
	{
		while (i < ac)
		{
			ft_extract_pathandname(av[i], &path, &name);
			ft_ls(ops, name, path);
			i++;
			ops.isfirst = 0;
			ft_free(name);
		}
	}
	return (0);
}
