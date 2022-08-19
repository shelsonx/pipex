/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/19 22:50:47 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int 	fd[2];
	int		infile_fd;
	int		outfile_fd;
	char	**first_command;
	char	**second_command;
	pid_t	first_pid;
	pid_t	second_pid;
	
	infile_fd = open(argv[1], O_RDONLY);
	outfile_fd = open(argv[argc -1], O_WRONLY | O_CREAT, 0777);
	first_command = ft_split(argv[2], ' ');
	second_command = ft_split(argv[3], ' ');
	if (infile_fd < 0 || outfile_fd < 0)
		return (1);
	if (pipe(fd) < 0)
	{
		return (2);
	}
	first_pid = fork();
	if (first_pid < 0)
		return (3);
	if (first_pid == 0)
	{
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(first_command[0], first_command, NULL);
	}
	second_pid = fork();
	if (second_pid < 0)
		return (4);
	if (second_pid == 0)
	{
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve(second_command[0], second_command, NULL);
	}
	close(fd[0]);
	close(fd[1]);
	close(infile_fd);
	close(outfile_fd);
	waitpid(first_pid, NULL, 0);
	waitpid(second_pid, NULL, 0);
}
