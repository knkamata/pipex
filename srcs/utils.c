/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:49:20 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/10 22:37:47 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*tmp;
	size_t	i;

	(void)cmd;
	i = 0;
	while (!ft_strstr(envp[i], "PATH"))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		exit(error_byname("ft_split"));
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		else
			free(path);
		i++;
	}
	return (0);
}

void	exec_cmd(char *argv, char *envp[])
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1)
		exit(error_notcmd());
}
