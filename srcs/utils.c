/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:01:07 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/18 09:42:46 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_util(int fd)
{
	if (close(fd) == -1)
		exit(error_byname("close"));
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
