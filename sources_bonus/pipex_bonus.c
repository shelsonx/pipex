/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/12 22:31:12 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	pipex(int argc, char **argv, char **envp)
{
	t_children_data	children_data;
	int				i;
	
	children_data.exit_status = -1;
	children_data.total_commands = argc - 3;
	create_pipes(&children_data);
	load_data(argc, argv, envp, &children_data);
	i = 2;
	while (i < children_data.total_commands)
	{
		validate(argv, children_data, i);
		i++;
	}
	return (exec_children_process(children_data, argv, envp));
}
