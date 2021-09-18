/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 07:38:21 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/18 12:09:14 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	write2pipe(char *limiter, int *fd)
{
	size_t	limiter_length;
	char	*line;

	limiter_length = ft_strlen(limiter);
	while (1)
	{
		ft_printf("pipex here_doc> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			close_util(fd[1]);
			exit(EXIT_FAILURE);
		}
		if (line[limiter_length] == '\n' && \
			!ft_strncmp(line, limiter, limiter_length))
		{
			close_util(fd[1]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd[1]);
		free_util(line);
	}
}

static void	init_heredoc(int argc, char *limiter)
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
	{
		close_util(fd[0]);
		write2pipe(limiter, fd);
	}
	else
	{
		close_util(fd[1]);
		dup2_util(fd[0], STDIN_FILENO);
		close_util(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

static int	open_file(char *file, t_open flag)
{
	int	fd;

	fd = 0;
	if (flag == APPEND)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC, 0644);
	if (flag == TRUNC)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
	if (flag == RDONLY)
		fd = open(file, O_RDONLY | O_CLOEXEC);
	if (fd == -1)
		error_nofile();
	return (fd);
}

void	here_doc(int argc, char *argv[], t_index *index)
{
	index->command = 3;
	index->final = open_file(argv[argc - 1], APPEND);
	init_heredoc(argc, argv[2]);
}

void	multiples(int argc, char *argv[], t_index *index)
{
	index->command = 2;
	index->start = open_file(argv[1], RDONLY);
	if (index->start > 0)
		dup2_util(index->start, STDIN_FILENO);
	else
		index->command++;
	index->final = open_file(argv[argc - 1], TRUNC);
}
