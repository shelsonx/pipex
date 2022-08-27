/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/27 05:26:19 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char **argv, char **envp)
{
	t_children_data	children_data;

	if (pipe(children_data.pipe_fd) < 0)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	children_data.first_data = get_data_first_cmd
		(argv, envp, children_data.pipe_fd);
	children_data.first_data.exec_command = get_exec_command
		(children_data.first_data.args[0], envp);
	children_data.last_data = get_data_last_cmd
		(argc, argv, envp, children_data.pipe_fd);
	children_data.last_data.exec_command = get_exec_command
		(children_data.last_data.args[0], envp);
	validate(argc, argv, envp, children_data);
	children_data.first_pid = create_child_process
		(execute_command, children_data.first_data);
	children_data.last_pid = create_child_process
		(execute_command, children_data.last_data);
	finish_data(children_data.first_data, children_data.last_data,
		children_data.pipe_fd);
	waitpid(children_data.first_pid, NULL, 0);
	waitpid(children_data.last_pid, NULL, 0);
	return (0);
}
