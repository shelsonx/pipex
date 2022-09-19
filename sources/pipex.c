/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/19 14:10:02 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char **argv, char **envp)
{
	t_children_data	children_data;

	if (pipe(children_data.pipe_fd) < 0)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	validate_empty_args(argv[2]);
	validate_empty_args(argv[argc -2]);
	load_data(argc, argv, envp, &children_data);
	validate_fd_files (children_data.first_data, children_data.last_data,
		argv, children_data.pipe_fd);
	validate_command(argc, argv, envp, children_data);
	exec_children_process(children_data);
	return (EXIT_SUCCESS);
}
