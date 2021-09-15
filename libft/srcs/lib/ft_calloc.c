/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:19:58 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/06 10:31:00 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size != 0 && count > SIZE_MAX / size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	p = (void *)malloc(count * size);
	if (!p)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(p, count * size);
	return (p);
}
