/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:52:18 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/18 08:41:43 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex <file1> <cmd1> <cmd2> ... <cmdn> <file2>
// ./pipex here_doc <LIMITER> <cmd1> <cmd2> <file>
int	main(int argc, char *argv[], char *envp[])
{
	t_index	index;

	if (!(argc >= 5))
		exit(error_argc());
	if (!ft_strncmp(argv[1], "here_doc", 8) && argv[1][8] == '\0')
		here_doc(argc, argv, &index);
	else
		multiples(argc, argv, &index);
	while (index.command < argc - 2)
		child_cmd(argv[index.command++], envp);
	if (index.final > 0)
		dup2(index.final, STDOUT_FILENO);
	exec_cmd(argv[argc - 2], envp);
	return (0);
}
