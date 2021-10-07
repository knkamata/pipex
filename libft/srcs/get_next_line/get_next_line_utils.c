/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 08:41:37 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/06 13:35:02 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/get_next_line.h"

void	clearfd(t_fd **fdlst, t_fd *target)
{
	t_fd	*tmp;

	if (!fdlst || !(*fdlst))
		return ;
	if (*fdlst == target)
	{
		*fdlst = target->next;
		free(target->content);
		free(target);
		return ;
	}
	tmp = *fdlst;
	while (tmp && (tmp->next != target))
		tmp = tmp->next;
	tmp->next = target->next;
	free(target->content);
	free(target);
}

t_fd	*newfd(int fd)
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

t_fd	*setfd(t_fd **fdlst, int fd)
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
