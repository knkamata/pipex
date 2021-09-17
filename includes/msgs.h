/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:31:02 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/18 08:02:18 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSGS_H
# define MSGS_H

// +------------------------------------------+ //
//   Error messages                             //
// +------------------------------------------+ //
# define ERRMSG "Error"
# define ERRMSG_ARGC "Error: Invalid number of arguments"
# define ERRMSG_USAGE1 "Usage: ./pipex <file1> <cmd1> <cmd2> ... <cmdn> <file2>"
# define ERRMSG_USAGE2 "Usage: ./pipex here_doc LIMITER <cmd1> <cmd2> <file>"
# define ERRMSG_NOTCMD "Error: Command not found"
# define ERRMSG_NOFILE "Error: No such file or directory"

#endif
