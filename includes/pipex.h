/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:47:23 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/22 16:16:11 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// +------------------------------------------+ //
//   Libft                                      //
// +------------------------------------------+ //
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

// +------------------------------------------+ //
//   Includes                                   //
// +------------------------------------------+ //
# include "msgs.h"

// +------------------------------------------+ //
//   System header files                        //
// +------------------------------------------+ //
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

// +------------------------------------------+ //
//   Type definition                            //
// +------------------------------------------+ //
typedef enum e_error
{
	ERRSTAT_GENERAL = 1,
	ERRSTAT_NOTCMD = 127,
}	t_error;

typedef enum e_open
{
	APPEND,
	TRUNC,
	RDONLY,
}	t_open;

typedef struct s_index
{
	int	start;
	int	final;
	int	command;
}	t_index;

// +------------------------------------------+ //
//   Prototypes                                 //
// +------------------------------------------+ //
//   - init.c                                   //
// +------------------------------------------+ //
void	here_doc(int argc, char *argv[], t_index *index);
void	multiples(int argc, char *argv[], t_index *index);

// +------------------------------------------+ //
//   - exec.c                                   //
// +------------------------------------------+ //
void	exec_cmd(char *argv, char *envp[]);
void	child_cmd(char *argv, char *envp[]);

// +------------------------------------------+ //
//   - error.c                                  //
// +------------------------------------------+ //
t_error	error_argc(void);
t_error	error_nofile(void);
t_error	error_notcmd(void);
t_error	error_byname(char *name);

// +------------------------------------------+ //
//   - utils.c                                  //
// +------------------------------------------+ //
void	close_util(int fd);
void	dup2_util(int fd1, int fd2);
void	free_util(void *ptr);

#endif
