/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/22 03:04:27 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int 	fd[2];
	pid_t	first_pid;
	pid_t	last_pid;
	
	if (pipe(fd) < 0)
	{
		perror("pipex");
		return (2);
	}
	t_data	data_first_cmd;
	data_first_cmd = get_data_first_cmd(argv, envp, fd);
	data_first_cmd.exec_command = get_exec_command(data_first_cmd.args[0], envp);
	first_pid = create_child_process(execute_command, data_first_cmd);
	
	t_data data_last_cmd;
	data_last_cmd = get_data_last_cmd(argc, argv, envp, fd);
	data_last_cmd.exec_command = get_exec_command(data_last_cmd.args[0], envp);
	last_pid = create_child_process(execute_command, data_last_cmd);
	
	ft_free_tab(data_first_cmd.args);
	ft_free_tab(data_last_cmd.args);
	close(fd[0]);
	close(fd[1]);
	close(data_first_cmd.file_fd);
	close(data_last_cmd.file_fd);
	waitpid(first_pid, NULL, 0);
	waitpid(last_pid, NULL, 0);
}
