/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:17:55 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/06 12:56:16 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	load_data(
	int argc, char **argv, char **envp, t_children_data *children_data)
{
	children_data->first_data = get_data_first_cmd
		(argv, envp, children_data->pipe_fd);
	children_data->first_data.exec_command = get_exec_command
		(children_data->first_data.args[0], envp);
	children_data->last_data = get_data_last_cmd
		(argc, argv, envp, children_data->pipe_fd);
	children_data->last_data.exec_command = get_exec_command
		(children_data->last_data.args[0], envp);
}
