/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:16:27 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/23 17:17:51 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_error	error_argc(void)
{
	ft_putendl_fd(ERRMSG_ARGC, STDERR_FILENO);
	ft_putendl_fd(ERRMSG_USAGE1, STDERR_FILENO);
	ft_putendl_fd(ERRMSG_USAGE2, STDERR_FILENO);
	return (ERRSTAT_GENERAL);
}

t_error	error_nofile(char *file)
{
	ft_putstr_fd(ERRMSG_NOFILE, STDERR_FILENO);
	ft_putendl_fd(file, STDERR_FILENO);
	return (ERRSTAT_GENERAL);
}

t_error	error_notcmd(char *cmd)
{
	ft_putstr_fd(ERRMSG_NOTCMD, STDERR_FILENO);
	ft_putendl_fd(cmd, STDERR_FILENO);
	return (ERRSTAT_NOTCMD);
}

t_error	error_byname(char *name)
{
	perror(name);
	return (ERRSTAT_GENERAL);
}
