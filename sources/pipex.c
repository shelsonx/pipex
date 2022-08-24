/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/24 21:07:06 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	first_pid;
	pid_t	last_pid;
	t_data	data_first_cmd;
	t_data	data_last_cmd;

	if (pipe(fd) < 0)
	{
		perror("pipex");
		exit(1);
	}
	data_first_cmd = get_data_first_cmd(argv, envp, fd);
	data_first_cmd.exec_command = get_exec_command
		(data_first_cmd.args[0], envp);
	data_last_cmd = get_data_last_cmd(argc, argv, envp, fd);
	data_last_cmd.exec_command = get_exec_command(data_last_cmd.args[0], envp);

	

	if (data_first_cmd.file_fd < 0 || data_last_cmd.file_fd < 0)
	{
		finish_data(data_first_cmd, data_last_cmd, fd);
		exit(1);
	}

	validate_command(argc, argv);
	if (!valid_first_command(argv, envp) && valid_last_command(argc, argv, envp))
	{
		finish_data(data_first_cmd, data_last_cmd, fd);
		exit(0);
	}
	else if (!valid_first_command(argv, envp))
	{
		finish_data(data_first_cmd, data_last_cmd, fd);
		exit(127);
	}
	else if (!valid_last_command(argc, argv, envp))
	{
		finish_data(data_first_cmd, data_last_cmd, fd);
		exit(127);
	}
	
	first_pid = create_child_process(execute_command, data_first_cmd);
	last_pid = create_child_process(execute_command, data_last_cmd);
	finish_data(data_first_cmd, data_last_cmd, fd);
	waitpid(first_pid, NULL, 0);
	waitpid(last_pid, NULL, 0);
}
