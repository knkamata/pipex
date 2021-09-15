/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:30:12 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/06 14:40:33 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**lsttmp;
	t_list	*nodetmp;

	if (!del || !lst || !(*lst))
		return ;
	lsttmp = lst;
	while (*lsttmp)
	{
		nodetmp = (*lsttmp)->next;
		ft_lstdelone(*lsttmp, del);
		*lsttmp = nodetmp;
	}
}
