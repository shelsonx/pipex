/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_children_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:11:10 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/27 15:12:17 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_children_process(t_children_data children_data)
{
	children_data.first_pid = create_child_process
		(execute_command, children_data.first_data);
	children_data.last_pid = create_child_process
		(execute_command, children_data.last_data);
	finish_data(children_data.first_data, children_data.last_data,
		children_data.pipe_fd);
	waitpid(children_data.first_pid, NULL, 0);
	waitpid(children_data.last_pid, NULL, 0);
}
