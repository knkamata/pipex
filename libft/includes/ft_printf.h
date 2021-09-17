/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:03:52 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/16 14:10:07 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// +------------------------------------------+ //
//   Headers                                    //
// +------------------------------------------+ //
# include <stdarg.h>

// +------------------------------------------+ //
//   Prototypes                                 //
// +------------------------------------------+ //
//      ft_printf.c                            //
// +------------------------------------------+ //
int		ft_printf(const char *format, ...);

// +------------------------------------------+ //
//      write                                   //
// +------------------------------------------+ //
int		write_char(va_list *args);
int		write_str(va_list *args);
int		write_int(va_list *args);
int		write_uint(va_list *args);
int		write_ptr(va_list *args);
int		write_hex(va_list *args, int c);

#endif
