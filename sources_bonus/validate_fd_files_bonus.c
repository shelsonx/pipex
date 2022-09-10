/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_fd_files_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:48:45 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/08 14:17:09 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	validate_fd_files(
	t_data first_data, t_data last_data, char **argv, int **pipe_fd)
{
	if (first_data.infile < 0)
	{
		finish_data(first_data, last_data, pipe_fd);
		if (!access(argv[1], F_OK))
			exit(EXIT_SUCCESS);
		else
			exit(EXIT_FAILURE);
	}
	if (last_data.outfile < 0)
	{
		finish_data(first_data, last_data, pipe_fd);
		exit(EXIT_FAILURE);
	}
}