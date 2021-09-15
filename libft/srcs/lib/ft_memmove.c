/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:52:29 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/06 14:52:30 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	uint8_t	*d;
	uint8_t	*s;

	d = (uint8_t *)dst;
	s = (uint8_t *)src;
	if (dst < src)
		while (len--)
			*d++ = *s++;
	if (dst > src)
		while (len--)
			d[len] = s[len];
	return (dst);
}
