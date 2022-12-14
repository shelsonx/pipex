/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_children_process_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:11:10 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/18 19:18:59 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_middles_commands(
	t_children_data *children_data, char **argv, char **envp)
{
	int	i;

	if (children_data->total_commands > 2)
	{
		i = 1;
		while (i <= (children_data->total_commands - 2))
		{
			children_data->middle_data = get_data_middle_cmd
				(argv, envp, children_data->pipe_fd, i);
			children_data->middle_data.exec_command = get_exec_command
				(children_data->middle_data.args[0], envp);
			if (!children_data->middle_data.exec_command)
			{
				ft_free_tab(children_data->middle_data.args);
				finish_data(children_data->first_data,
					children_data->last_data, children_data->pipe_fd);
				exit(COMMAND_NOT_FOUND);
			}
			children_data->middle_pid = create_child_process
				(execute_command, children_data->middle_data);
			ft_free_tab(children_data->middle_data.args);
			i++;
		}
	}
}

void	exec_children_process(
	t_children_data children_data, char **argv, char **envp)
{
	int		status;

	status = 0;
	children_data.first_pid = create_child_process
		(execute_command, children_data.first_data);
	if (!children_data.first_data.exec_command)
	{
		finish_data(children_data.first_data, children_data.last_data,
			children_data.pipe_fd);
		exit(COMMAND_NOT_FOUND);
	}
	exec_middles_commands(&children_data, argv, envp);
	children_data.last_pid = create_child_process
		(execute_command, children_data.last_data);
	finish_data(children_data.first_data, children_data.last_data,
		children_data.pipe_fd);
	waitpid(children_data.first_pid, &status, 0);
	if (children_data.total_commands > 2)
		waitpid(children_data.middle_pid, &status, 0);
	waitpid(children_data.last_pid, &status, 0);
}
