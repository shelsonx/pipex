/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:46:35 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/09 22:25:43 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_data	get_data_first_cmd(char **argv, char **envp, int **fd)
{
	t_data	data;
	char	*msg;

	data.infile = open(argv[1], O_RDONLY);
	if (data.infile < 0)
	{
		msg = ft_strjoin("pipex: ", argv[1]);
		perror(msg);
		free(msg);
	}
	data.fd = fd;
	data.fd_in = data.infile;
	data.fd_out = fd[0][1];
	data.args = create_command(argv[2]);
	data.exec_command = get_exec_command(data.args[0], envp);
	return (data);
}

t_data	get_data_middle_cmd(char **argv, char **envp, int **fd)
{
	t_data	data;
	data.fd = fd;
	data.fd_in = fd[0][0];
	data.fd_out = fd[1][1];
	data.args = create_command(argv[3]);
	data.exec_command = get_exec_command(data.args[0], envp);
	return (data);
}

t_data	get_data_last_cmd(int argc, char **argv, char **envp, int **fd)
{
	t_data	data;
	char	*msg;

	data.outfile = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data.outfile < 0)
	{
		msg = ft_strjoin("pipex: ", argv[argc -1]);
		perror(msg);
		free(msg);
	}
	data.fd = fd;
	if (argc == 5)
		data.fd_in = fd[0][0];
	else
		data.fd_in = fd[1][0];
	data.fd_out = data.outfile;
	data.args = create_command(argv[argc -2]);
	data.exec_command = get_exec_command(data.args[0], envp);
	return (data);
}
