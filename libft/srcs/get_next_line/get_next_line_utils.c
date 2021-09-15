/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 08:41:37 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/09 19:48:31 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

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
