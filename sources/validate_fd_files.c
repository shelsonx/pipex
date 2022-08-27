/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_fd_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:48:45 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/27 14:55:06 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	validate_fd_files(
	t_data first_data, t_data last_data, char **argv, int *pipe_fd)
{
	if (first_data.file_fd < 0)
	{
		finish_data(first_data, last_data, pipe_fd);
		if (!access(argv[1], F_OK))
			exit(EXIT_SUCCESS);
		else
			exit(EXIT_FAILURE);
	}
	if (last_data.file_fd < 0)
	{
		finish_data(first_data, last_data, pipe_fd);
		exit(EXIT_FAILURE);
	}
}
