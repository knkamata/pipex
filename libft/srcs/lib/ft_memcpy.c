/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:11:26 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/06 11:28:53 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	uint8_t	*d;
	uint8_t	*s;

	if (!dst && !src)
		return (NULL);
	d = (uint8_t *)dst;
	s = (uint8_t *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
