/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/21 07:36:58 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int 	fd[2];
	int		infile_fd;
	int		outfile_fd;
	char	**first_command;
	char	**second_command;
	pid_t	first_pid;
	pid_t	second_pid;
	
	infile_fd = open(argv[1], O_RDONLY);
	outfile_fd = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	first_command = create_command(argv[2]);
	second_command = create_command(argv[3]);
	if (infile_fd < 0 || outfile_fd < 0)
	{
		perror("pipex");
		return (-1);
	}
	if (pipe(fd) < 0)
	{
		return (2);
	}

	t_data data_first_cmd;
	data_first_cmd.file_fd = infile_fd;
	data_first_cmd.pipe_read_fd = fd[0];
	data_first_cmd.pipe_write_fd = fd[1];
	data_first_cmd.first_std = STDIN_FILENO;
	data_first_cmd.second_std = STDOUT_FILENO;
	data_first_cmd.args = first_command;
	data_first_cmd.exec_command = get_exec_command(first_command[0], envp);
	first_pid = create_child_process(execute_command, data_first_cmd);
	
	

	/* second_pid = fork();
	if (second_pid < 0)
		return (4);
	if (second_pid == 0)
	{
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
		char *second_exec_cmd = get_exec_command(second_command[0], envp);
		if (second_exec_cmd)
			execve(second_exec_cmd, second_command, NULL);
		free(second_exec_cmd);
	} */
	
	
	ft_free_tab(first_command);
	ft_free_tab(second_command);
	close(fd[0]);
	close(fd[1]);
	close(infile_fd);
	close(outfile_fd);
	waitpid(first_pid, NULL, 0);
	waitpid(second_pid, NULL, 0);
}
