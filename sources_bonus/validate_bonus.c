/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 05:22:47 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/18 19:10:22 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	validate(
	char **argv, t_children_data children_data)
{
	int	i;

	i = 2;
	validate_empty_args(argv[i]);
	validate_empty_args(argv[i +1]);
	validate_fd_files (children_data.first_data, children_data.last_data,
		argv, children_data.pipe_fd);
}

t_range	get_valid_cmds_range(t_children_data children_data, char **argv)
{
	t_range	range;

	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		range.start = 3;
		range.end = children_data.total_commands + 2;
	}
	else
	{
		range.start = 2;
		range.end = children_data.total_commands + 1;
	}
	return (range);
}
