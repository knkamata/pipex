/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:51:12 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/06 14:51:13 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	tail = head;
	while (lst->next)
	{
		lst = lst->next;
		tail->next = ft_lstnew(f(lst->content));
		if (!(tail->next))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tail = tail->next;
	}
	return (head);
}
