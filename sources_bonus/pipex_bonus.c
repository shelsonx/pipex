/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/27 15:30:01 by sjhony-x         ###   ########.fr       */
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
	load_data(argc, argv, envp, &children_data);
	validate(argc, argv, envp, children_data);
	exec_children_process(children_data);
	return (EXIT_SUCCESS);
}
