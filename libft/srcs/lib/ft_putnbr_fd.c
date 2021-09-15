/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:52:12 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/06 14:52:13 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int64_t	nn;

	nn = n;
	if (nn < 0)
	{
		ft_putchar_fd('-', fd);
		nn *= -1;
	}
	if (nn >= 10)
		ft_putnbr_fd(nn / 10, fd);
	ft_putchar_fd('0' + (nn % 10), fd);
}
