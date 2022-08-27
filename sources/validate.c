/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 05:22:47 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/27 05:27:22 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	validate(
	int argc, char **argv, char **envp, t_children_data children_data)
{
	validate_empty_args(argv[2]);
	validate_empty_args(argv[argc -2]);
	validate_fd_files (children_data.first_data, children_data.last_data,
		argv, children_data.pipe_fd);
	validate_command(argc, argv, envp, children_data);
}
