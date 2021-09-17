/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 08:39:13 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/16 14:05:39 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	return_new_line(t_fd *target, char *nptr, char **res)
{
	char	*tmp;

	if (nptr)
	{
		*res = ft_strndup(target->content, nptr - (target->content) + 1);
		tmp = ft_strndup(nptr + 1, ft_strlen(nptr + 1));
		if (!*res || !tmp)
			return (ERROR);
		free(target->content);
		target->content = tmp;
		return (SUCCESS);
	}
	else
	{
		if (target->content && *(target->content) == '\0')
			*res = NULL;
		else
		{
			*res = ft_strndup(target->content, ft_strlen(target->content));
			tmp = ft_strndup("", 0);
			free(target->content);
			target->content = tmp;
		}
		return (ENDOFFILE);
	}
}

static int	readfd(t_fd *target, char *buf, char **res)
{
	char		*nptr;
	char		*tmp;
	ssize_t		cc;

	while (1)
	{
		nptr = ft_strchr(target->content, '\n');
		if (nptr)
			break ;
		cc = read(target->value, buf, BUFFER_SIZE);
		if (cc == -1)
			return (ERROR);
		if (cc == 0)
			break ;
		buf[cc] = '\0';
		tmp = ft_strjoin(target->content, buf);
		if (!tmp)
			return (ERROR);
		free(target->content);
		target->content = tmp;
	}
	return (return_new_line(target, nptr, res));
}

static t_fd	*newfd(int fd)
{
	t_fd	*new;

	new = (t_fd *)malloc(sizeof(t_fd));
	if (!new)
		return (NULL);
	new->value = fd;
	new->content = ft_strndup("", 0);
	new->next = NULL;
	return (new);
}

static t_fd	*setfd(t_fd **fdlst, int fd)
{
	t_fd	*target;

	if (!fdlst)
		return (NULL);
	target = *fdlst;
	if (!target)
	{
		target = newfd(fd);
		*fdlst = target;
		return (target);
	}
	while (target && (target->value != fd))
		target = target->next;
	if (target)
		return (target);
	target = newfd(fd);
	target->next = *fdlst;
	*fdlst = target;
	return (target);
}

char	*get_next_line(int fd)
{
	static t_fd		*fdlst;
	t_fd			*target;
	char			*buf;
	char			*res;
	int				status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	target = setfd(&fdlst, fd);
	if (!target)
		return (NULL);
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	res = NULL;
	status = readfd(target, buf, &res);
	free(buf);
	if (status == ENDOFFILE || status == ERROR)
		clearfd(&fdlst, target);
	if (status == ERROR)
		return (NULL);
	return (res);
}
