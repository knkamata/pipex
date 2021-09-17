/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:14:04 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/16 14:14:06 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_str(va_list *args)
{
	char	*str;
	int		cnt;

	cnt = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	cnt = write(1, str, ft_strlen(str));
	return (cnt);
}
