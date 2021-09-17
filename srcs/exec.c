/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:49:20 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/18 07:30:51 by kkamata          ###   ########.fr       */
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
	if (!cmd)
		exit(error_byname("ft_split"));
	if (ft_strchr(cmd[0], '/'))
		if (execve(cmd[0], &cmd[0], envp) == -1)
			exit(error_notcmd());
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1)
		exit(error_notcmd());
}

void	child_cmd(char *argv, char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_byname("pipe");
	pid = fork();
	if (pid == -1)
		error_byname("fork");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exec_cmd(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(-1, NULL, WNOHANG);
	}
}