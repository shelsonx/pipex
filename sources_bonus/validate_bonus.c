/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 05:22:47 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/12 00:03:48 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	validate(
	char **argv, t_children_data children_data, int i)
{
	validate_empty_args(argv[i]);
	validate_empty_args(argv[i +1]);
	validate_fd_files (children_data.first_data, children_data.last_data,
		argv, children_data.pipe_fd);
}
