/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:51:36 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/06 11:49:24 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*select_node(t_list **p_head, size_t fd)
{
	t_list			*node;

	node = *p_head;
	while (node)
	{
		if (node->content_size == fd)
			return (node);
		node = node->next;
	}
	return (node = ft_lstinsert(p_head, "", fd));
}

t_list		*fill_contents(t_list *node, int fd, int *p_ret)
{
	char			buf[GNL_BUFF + 1];
	char			*to_free;
	size_t			nbytes;

	while (!(ft_strchr((char *)(node->content), '\n')))
	{
		if ((nbytes = (size_t)read(fd, buf, GNL_BUFF)) == 0)
			break ;
		to_free = node->content;
		buf[nbytes] = '\0';
		node->content = ft_strjoin((char *)(node->content), buf);
		free(to_free);
	}
	*p_ret = (int)nbytes;
	return (node);
}

int			copy_line(t_list *node, char **p_line)
{
	char			*tmp;
	char			*bytes_read;
	size_t			line_len;

	bytes_read = (char *)(node->content);
	line_len = 0;
	while (bytes_read[line_len] && bytes_read[line_len] != '\n')
		line_len++;
	if (!(tmp = (char *)ft_malloc_bzero(sizeof(char) * (line_len + 1))))
		return (-1);
	ft_memmove(tmp, bytes_read, line_len);
	tmp[line_len] = '\0';
	*p_line = tmp;
	return (bytes_read[line_len] == '\n' ? (int)(++line_len) : (int)line_len);
}

void		free_node(t_list **p_head, size_t fd)
{
	t_list			*node;
	size_t			index;

	index = 0;
	node = *p_head;
	while (node && node->content_size != fd)
	{
		index++;
		node = node->next;
	}
	ft_lstdelnode(p_head, index);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*node;
	t_list			*head;
	char			*to_free;
	unsigned char	eof_read;
	int				ret;

	if (fd < 0 || !line || read(fd, 0, 0) < 0 || (ret = 0))
		return (-1);
	head = node;
	if (!(node = select_node(&head, (size_t)fd)))
		return (-1);
	node = fill_contents(node, fd, &ret);
	eof_read = (ret == 0 ? 1 : 0);
	if ((ret = copy_line(node, line)) == -1)
		return (-1);
	to_free = node->content;
	node->content = ft_strdup(node->content + ret);
	free(to_free);
	if (eof_read && ret == 0)
		free_node(&head, (size_t)fd);
	node = head;
	return (ret ? 1 : 0);
}
