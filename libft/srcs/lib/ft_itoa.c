/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:54:21 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/06 14:24:42 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int64_t	nn;
	size_t	len;
	char	*dst;

	nn = n;
	len = ft_numlen(nn);
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	if (nn == 0)
		dst[0] = '0';
	if (nn < 0)
	{
		dst[0] = '-';
		nn *= -1;
	}
	dst[len--] = '\0';
	while (nn > 0)
	{
		dst[len--] = nn % 10 + '0';
		nn /= 10;
	}
	return (dst);
}
