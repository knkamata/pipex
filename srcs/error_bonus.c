/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:16:27 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/10 22:11:22 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_bool	error_argc(void)
{
	ft_putendl_fd(ERRMSG_ARGC, STDERR_FILENO);
	ft_putendl_fd(ERRMSG_USAGE, STDOUT_FILENO);
	return(FALSE);
}

t_bool	error_notcmd(void)
{
	ft_putendl_fd(ERRMSG_NOTCMD, STDERR_FILENO);
	return(FALSE);
}

t_bool	error_byname(char *name)
{
	perror(name);
	return(FALSE);
}
