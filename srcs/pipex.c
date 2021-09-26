/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:52:18 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/26 19:12:22 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	write2pipe(char *limiter, int fd[2])
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
			close_util(fd);
			exit(EXIT_FAILURE);
		}
		if (line[limiter_length] == '\n' && limiter != NULL && \
			!ft_strncmp(line, limiter, limiter_length))
		{
			close_util(fd);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd[1]);
		free_util(line);
	}
}

static void	here_doc(int argc, char *argv[])
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
		write2pipe(argv[2], fd);
	else
	{
		dup2_util(fd[0], STDIN_FILENO);
		close_util(fd);
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
		error_nofile(file);
	return (fd);
}

// ./pipex <file1> <cmd1> <cmd2> ... <cmdn> <file2>
// ./pipex here_doc <LIMITER> <cmd1> <cmd2> <file>
int	main(int argc, char *argv[], char *envp[])
{
	t_files	files;
	int		cmd_index;

	if (!(argc >= 5))
		return (error_argc());
	if (argv[1] != NULL && !ft_strncmp(argv[1], "here_doc", 8) && argv[1][8] == '\0')
	{
		cmd_index = 3;
		here_doc(argc, argv);
		files.output = open_file(argv[argc - 1], APPEND);
	}
	else
	{
		cmd_index = 2;
		files.input = open_file(argv[1], RDONLY);
		if (files.input > 0)
			dup2_util(files.input, STDIN_FILENO);
		files.output = open_file(argv[argc - 1], TRUNC);
	}
	while (cmd_index < argc - 2)
		child_cmd(argv[cmd_index++], envp, files);
	if (files.output == -1)
		exit(EXIT_FAILURE);
	dup2_util(files.output, STDOUT_FILENO);
	exec_cmd(argv[argc - 2], envp);
}
