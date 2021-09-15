/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:04:20 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/06 11:34:57 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	uint8_t	*str;

	str = (uint8_t *)s;
	while (n--)
	{
		if (*str == (uint8_t)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
