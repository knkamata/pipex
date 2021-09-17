/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:52:18 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/17 14:49:39 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write2pipe(char *limiter, int *fd)
{
	size_t	limiter_length;
	char	*line;

	close(fd[0]);
	limiter_length = ft_strlen(limiter);
	while (1)
	{
		ft_printf("pipex here_doc> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			close(fd[1]);
			exit(EXIT_FAILURE);
		}
		if (line[limiter_length] == '\n' && \
			!ft_strncmp(line, limiter, limiter_length))
		{
			close(fd[1]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
		line = NULL;
	}
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
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(int argc, char *limiter)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 6)
		exit(error_argc());
	if (pipe(fd) == -1)
		exit(error_byname("pipe"));
	pid = fork();
	if (pid == -1)
		error_byname("fork");
	if (pid == 0)
		write2pipe(limiter, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

int	open_file(char *file, t_open flag)
{
	int	fd;

	fd = 0;
	if (flag == FT_APPEND)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (flag == FT_TRUNC)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (flag == FT_RDONLY)
		fd = open(file, O_RDONLY);
	if (fd == -1)
		error_nofile();
	return (fd);
}

// ./pipex <file1> <cmd1> <cmd2> ... <cmdn> <file2>
// ./pipex here_doc <LIMITER> <cmd1> <cmd2> <file>
int	main(int argc, char *argv[], char *envp[])
{
	int	start;
	int	final;
	int	cmd_index;

	if (!(argc >= 5))
		exit(error_argc());
	final = 1;
	if (!ft_strncmp(argv[1], "here_doc", 8) && argv[1][8] == '\0')
	{
		cmd_index = 3;
		here_doc(argc, argv[2]);
		final = open_file(argv[argc - 1], FT_APPEND);
	}
	else
	{
		cmd_index = 2;
		start = open_file(argv[1], FT_RDONLY);
		final = open_file(argv[argc - 1], FT_TRUNC);
		dup2(start, STDIN_FILENO);
	}
	while (cmd_index < argc - 2)
		child_cmd(argv[cmd_index++], envp);
	dup2(final, STDOUT_FILENO);
	exec_cmd(argv[argc - 2], envp);
	return (0);
}
