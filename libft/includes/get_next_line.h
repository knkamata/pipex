/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 08:39:59 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/28 14:35:30 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// +------------------------------------------+ //
//   Headers                                    //
// +------------------------------------------+ //

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

// +------------------------------------------+ //
//   Macro definition                           //
// +------------------------------------------+ //

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# define SUCCESS 1
# define ENDOFFILE 0
# define ERROR -1

// +------------------------------------------+ //
//   Type definition                            //
// +------------------------------------------+ //

typedef struct s_fd
{
	int				value;
	char			*content;
	struct s_fd		*next;
}	t_fd;

// +------------------------------------------+ //
//   get_next_line.c                            //
// +------------------------------------------+ //

char	*get_next_line(int fd);

// +------------------------------------------+ //
//   get_next_line_utils.c                      //
// +------------------------------------------+ //

void	clearfd(t_fd **fdlst, t_fd *target);

#endif
