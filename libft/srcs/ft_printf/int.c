/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:13:32 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/16 14:13:34 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_int(va_list *args)
{
	char	*num;
	int		tmp;
	int		cnt;

	tmp = va_arg(*args, int);
	num = ft_itoa(tmp);
	if (!num)
		return (0);
	cnt = write(1, num, ft_strlen(num));
	free(num);
	return (cnt);
}
