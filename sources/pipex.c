/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/20 15:12:42 by sjhony-x         ###   ########.fr       */
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
		char *path_1 = join_path_command("/bin", first_command[0]);
		execve(path_1, first_command, NULL);
		free(path_1);
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
		char *path_2 = join_path_command("/bin", second_command[0]);
		execve(path_2, second_command, NULL);
		free(path_2);
	}
	ft_free_tab(first_command);
	ft_free_tab(second_command);
	close(fd[0]);
	close(fd[1]);
	close(infile_fd);
	close(outfile_fd);
	waitpid(first_pid, NULL, 0);
	waitpid(second_pid, NULL, 0);
}
