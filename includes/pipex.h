/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:47:23 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/26 18:34:37 by kkamata          ###   ########.fr       */
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
	ERRSTAT_NOPERM = 126,
	ERRSTAT_NOTCMD = 127,
}	t_error;

typedef enum e_open
{
	APPEND,
	TRUNC,
	RDONLY,
}	t_open;

typedef struct s_files
{
	int	input;
	int	output;
}	t_files;

// +------------------------------------------+ //
//   Prototypes                                 //
// +------------------------------------------+ //
//   - exec.c                                   //
// +------------------------------------------+ //

void	exec_cmd(char *argv, char *envp[]);
void	child_cmd(char *argv, char *envp[], t_files files);

// +------------------------------------------+ //
//   - error.c                                  //
// +------------------------------------------+ //

t_error	error_argc(void);
t_error	error_nofile(char *file);
t_error	error_notcmd(char *cmd);
t_error	error_noperm(char *name);
t_error	error_byname(char *name);

// +------------------------------------------+ //
//   - utils.c                                  //
// +------------------------------------------+ //

void	close_util(int fd[2]);
void	dup2_util(int fd1, int fd2);
void	free_util(void *ptr);

#endif
