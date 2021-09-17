/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:47:23 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/18 07:40:27 by kkamata          ###   ########.fr       */
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
	FT_APPEND,
	FT_TRUNC,
	FT_RDONLY,
}	t_open;

typedef struct e_index
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
char	*find_path(char *cmd, char **envp);
void	exec_cmd(char *argv, char *envp[]);
void	child_cmd(char *argv, char *envp[]);

// +------------------------------------------+ //
//   - error.c                                  //
// +------------------------------------------+ //
t_error	error_argc(void);
t_error	error_nofile(void);
t_error	error_notcmd(void);
t_error	error_byname(char *name);

#endif
