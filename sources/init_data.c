/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:46:35 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/03 22:27:09 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	get_data_first_cmd(char **argv, char **envp, int *fd)
{
	t_data	data;
	char	*msg;

	data.file_fd = open(argv[1], O_RDONLY);
	if (data.file_fd < 0)
	{
		msg = ft_strjoin("pipex: ", argv[1]);
		perror(msg);
		free(msg);
	}
	data.first_redirect_pipe = fd[0];
	data.second_redirect_pipe = fd[1];
	data.first_redirect_std = STDIN_FILENO;
	data.second_redirect_std = STDOUT_FILENO;
	data.args = create_command(argv[2]);
	data.exec_command = get_exec_command(data.args[0], envp);
	return (data);
}

t_data	get_data_last_cmd(int argc, char **argv, char **envp, int *fd)
{
	t_data	data;
	char	*msg;

	data.file_fd = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data.file_fd < 0)
	{
		msg = ft_strjoin("pipex: ", argv[argc -1]);
		perror(msg);
		free(msg);
	}
	data.first_redirect_pipe = fd[1];
	data.second_redirect_pipe = fd[0];
	data.first_redirect_std = STDOUT_FILENO;
	data.second_redirect_std = STDIN_FILENO;
	data.args = create_command(argv[argc -2]);
	data.exec_command = get_exec_command(data.args[0], envp);
	return (data);
}
