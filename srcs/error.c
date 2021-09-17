/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:16:27 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/17 16:46:37 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_error	error_argc(void)
{
	ft_putendl_fd(ERRMSG_ARGC, STDERR_FILENO);
	ft_putendl_fd(ERRMSG_USAGE1, STDOUT_FILENO);
	ft_putendl_fd(ERRMSG_USAGE2, STDOUT_FILENO);
	return (ERRSTAT_GENERAL);
}

t_error	error_nofile(void)
{
	ft_putendl_fd(ERRMSG_NOFILE, STDERR_FILENO);
	return (ERRSTAT_GENERAL);
}

t_error	error_notcmd(void)
{
	ft_putendl_fd(ERRMSG_NOTCMD, STDERR_FILENO);
	return (ERRSTAT_NOTCMD);
}

t_error	error_byname(char *name)
{
	perror(name);
	return (ERRSTAT_GENERAL);
}
