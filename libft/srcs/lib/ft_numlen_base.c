/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:52:08 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/06 10:53:43 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen_base(int64_t n, uint64_t base)
{
	size_t	len;

	if (base < 2)
		return (0);
	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}
