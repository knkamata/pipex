/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 08:39:59 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/06 13:49:27 by kkamata          ###   ########.fr       */
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

// +------------------------------------------+ //
//   Enum definition                            //
// +------------------------------------------+ //

typedef enum e_gnl
{
	GNLSUC = 1,
	GNLEOF = 0,
	GNLERR = -1,
}	t_gnl;

// +------------------------------------------+ //
//   Struct definition                          //
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
//   get_next_line_beta.c                       //
// +------------------------------------------+ //

// Returns 1 (SUCCESS), 0 (EOF), -1 (ERROR) and sets a line read until before \n
int		get_next_line_beta(int fd, char **line);

// +------------------------------------------+ //
//   get_next_line_utils.c                      //
// +------------------------------------------+ //

t_fd	*newfd(int fd);
t_fd	*setfd(t_fd **fdlst, int fd);
void	clearfd(t_fd **fdlst, t_fd *target);

#endif
