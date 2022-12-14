/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:46:35 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/19 06:19:00 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	exit_bad_infile(int **fd, char **argv)
{
	if (!access(argv[1], F_OK))
	{
		close_fds(fd);
		ft_free_fds(fd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close_fds(fd);
		ft_free_fds(fd);
		exit(EXIT_FAILURE);
	}
}

t_data	get_data_first_cmd(char **argv, char **envp, int **fd)
{
	t_data	data;
	char	*msg;

	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		set_infile_here_doc(&data, argv);
	else
		data.infile = open(argv[1], O_RDONLY);
	if (data.infile < 0)
	{
		msg = ft_strjoin("pipex: ", argv[1]);
		perror(msg);
		free(msg);
		exit_bad_infile(fd, argv);
	}
	data.fd = fd;
	data.fd_in = data.infile;
	data.fd_out = fd[0][1];
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		data.args = create_command(argv[3]);
	else
		data.args = create_command(argv[2]);
	data.exec_command = get_exec_command(data.args[0], envp);
	return (data);
}

t_data	get_data_middle_cmd(char **argv, char **envp, int **fd, int i)
{
	t_data	data;

	data.fd = fd;
	data.fd_in = fd[i -1][0];
	data.fd_out = fd[i][1];
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		data.args = create_command(argv[i +3]);
	else
		data.args = create_command(argv[i +2]);
	data.exec_command = get_exec_command(data.args[0], envp);
	return (data);
}

t_data	get_data_last_cmd(int argc, char **argv, char **envp, int **fd)
{
	t_data	data;
	char	*msg;

	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		data.outfile = open(argv[argc -1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		data.outfile = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data.outfile < 0)
	{
		msg = ft_strjoin("pipex: ", argv[argc -1]);
		perror(msg);
		free(msg);
	}
	data.fd = fd;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		data.fd_in = fd[argc -6][0];
	else
		data.fd_in = fd[argc -5][0];
	data.args = create_command(argv[argc -2]);
	data.fd_out = data.outfile;
	data.exec_command = get_exec_command(data.args[0], envp);
	return (data);
}

void	create_pipes(t_children_data *children_data)
{
	int	i;

	children_data->pipe_fd = ft_calloc
		(sizeof(int **), children_data->total_commands);
	i = 0;
	while (i < (children_data->total_commands -1))
	{
		children_data->pipe_fd[i] = ft_calloc(sizeof(int *), 2);
		if (pipe(children_data->pipe_fd[i]) < 0)
		{
			perror("pipex");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
