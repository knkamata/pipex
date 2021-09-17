/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uiota.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:22:53 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/16 13:23:19 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
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
	dst[len--] = '\0';
	while (nn > 0)
	{
		dst[len--] = nn % 10 + '0';
		nn /= 10;
	}
	return (dst);
}
