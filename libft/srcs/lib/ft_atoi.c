/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:04:38 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/09 18:27:19 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int64_t	res;
	int8_t	sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
	{
		if (res > (LONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			if (sign == -1)
				return ((int)LONG_MIN);
		}
		res = (res * 10) + (*str++ - '0');
	}
	return ((int)res * sign);
}
