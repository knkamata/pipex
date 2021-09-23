/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:17:32 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/23 17:18:17 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	close_fd(int fd)
{
	if (close(fd) == -1)
		exit(error_byname("close"));
}

void	close_util(int fd[2])
{
	close_fd(fd[0]);
	close_fd(fd[1]);
}

void	dup2_util(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		exit(error_byname("dup2"));
}

void	free_util(void *ptr)
{
	free(ptr);
	ptr = NULL;
}