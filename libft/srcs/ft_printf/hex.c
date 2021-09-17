/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:13:12 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/16 14:13:13 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_hex(va_list *args, int c)
{
	unsigned int	hex;
	int				cnt;

	cnt = 0;
	hex = (unsigned int)va_arg(*args, unsigned int);
	if (c == 'x')
		cnt += ft_putnbr_base(hex, "0123456789abcdef");
	if (c == 'X')
		cnt += ft_putnbr_base(hex, "0123456789ABCDEF");
	return (cnt);
}
