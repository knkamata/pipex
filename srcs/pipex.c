/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:46:01 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/10 21:49:56 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *argv[], char *envp[], int *fd)
{
	int	fdin;

	fdin = open(argv[1], O_RDONLY);
	dup2(fd[1], STDOUT_FILENO);
	dup2(fdin, STDIN_FILENO);
	close(fd[0]);
	exec_cmd(argv[2], envp);
}

void	parent_process(char *argv[], char *envp[], int *fd)
{
	int	fdout;

	fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	dup2(fd[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	close(fd[1]);
	exec_cmd(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		exit(error_argc());
	if (pipe(fd) == -1)
		exit(error_byname("pipe"));
	pid = fork();
	if (pid == -1)
		exit(error_byname("fork"));
	if (pid == 0)
		child_process(argv, envp, fd);
	waitpid(pid, NULL, 0);
	parent_process(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
