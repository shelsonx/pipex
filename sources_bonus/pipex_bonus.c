/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/10 19:23:25 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_pipes(t_children_data *children_data)
{
	int	i;

	children_data->pipe_fd = (int **) malloc(sizeof(int *) * (children_data->total_commands));
	i = 0;
	while (i < (children_data->total_commands - 1))
	{
		children_data->pipe_fd[i] = (int *) malloc(sizeof(int) * 2);
		if (pipe(children_data->pipe_fd[i]) < 0)
		{
			perror("pipex");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	pipex(int argc, char **argv, char **envp)
{
	
	t_children_data	children_data;

	children_data.total_commands = argc - 3;
	create_pipes(&children_data);
	load_data(argc, argv, envp, &children_data);
	validate(argc, argv, envp, children_data);
	exec_children_process(children_data, argv, envp);
	return (EXIT_SUCCESS);
}
