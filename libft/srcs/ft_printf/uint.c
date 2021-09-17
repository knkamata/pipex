/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:14:22 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/16 14:14:23 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_uint(va_list *args)
{
	char			*num;
	unsigned int	tmp;
	int				cnt;

	tmp = va_arg(*args, unsigned int);
	num = ft_uitoa(tmp);
	if (!num)
		return (0);
	cnt = write(1, num, ft_strlen(num));
	free(num);
	return (cnt);
}
