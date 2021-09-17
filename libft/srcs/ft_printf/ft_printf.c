/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 22:22:57 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/16 14:12:21 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	specify(const char **format, va_list *args)
{
	int	res;

	if (!format || !(*format) || !args)
		return (0);
	res = 0;
	(*format)++;
	if (**format == 'c')
		res = write_char(args);
	if (**format == 's')
		res = write_str(args);
	if (**format == 'd' || **format == 'i')
		res = write_int(args);
	if (**format == 'u')
		res = write_uint(args);
	if (**format == 'p')
		res = write_ptr(args);
	if (**format == 'x' || **format == 'X')
		res = write_hex(args, **format);
	if (**format == '%')
		res = write(1, "%", 1);
	(*format)++;
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			res;

	if (!format)
		return (0);
	res = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			res += specify(&format, &args);
		else
			res += write(1, format++, 1);
	}
	va_end(args);
	return (res);
}
