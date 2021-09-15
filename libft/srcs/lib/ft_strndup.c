/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:29:58 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/09 20:27:24 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;

	if (n >= SIZE_MAX)
	{
		errno = ENOMEM;
		return (NULL);
	}
	dst = (char *)malloc(n + 1);
	if (!dst)
	{
		errno = ENOMEM;
		return (NULL);
	}
	dst = ft_memmove(dst, s1, n);
	dst[n] = '\0';
	return (dst);
}
