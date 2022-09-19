/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:35:57 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/19 06:18:35 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	validate_empty_args(char *arg, t_children_data *children_data)
{
	int		i;
	size_t	count_space;

	if (arg[0] == '\0')
	{
		close_fds(children_data->pipe_fd);
		ft_free_fds(children_data->pipe_fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	count_space = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			count_space++;
		i++;
	}
	if (count_space == ft_strlen(arg))
	{
		close_fds(children_data->pipe_fd);
		ft_free_fds(children_data->pipe_fd);
		exit(EXIT_FAILURE);
	}
}
