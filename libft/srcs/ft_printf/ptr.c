/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:37:36 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/17 14:37:37 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_ptr(va_list *args)
{
	size_t	addr;
	int		cnt;

	cnt = 0;
	cnt += write(1, "0x", 2);
	addr = (size_t)va_arg(*args, void *);
	cnt += ft_putnbr_base(addr, "0123456789abcdef");
	return (cnt);
}
