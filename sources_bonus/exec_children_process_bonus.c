/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_children_process_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:11:10 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/08 14:20:01 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_children_process(t_children_data children_data)
{
	children_data.first_pid = create_child_process
		(execute_command, children_data.first_data);
	children_data.middle_pid = create_child_process
		(execute_command, children_data.middle_data);
	children_data.last_pid = create_child_process
		(execute_command, children_data.last_data);
	finish_data(children_data.first_data, children_data.last_data,
		children_data.pipe_fd);
	waitpid(children_data.first_pid, NULL, 0);
	waitpid(children_data.middle_pid, NULL, 0);
	waitpid(children_data.last_pid, NULL, 0);
}
