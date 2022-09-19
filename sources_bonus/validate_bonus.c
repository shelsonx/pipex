/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 05:22:47 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/19 06:07:08 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	validate(
	char **argv, t_children_data children_data)
{
	int	i;

	i = 2;
	while (i <= children_data.total_commands + 1)
	{
		validate_empty_args(argv[i], &children_data);
		validate_empty_args(argv[i +1], &children_data);
		i++;
	}
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
