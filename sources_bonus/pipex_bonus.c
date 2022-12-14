/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/19 06:10:44 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	pipex(int argc, char **argv, char **envp)
{
	t_children_data	children_data;
	char			*last_command;

	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		children_data.total_commands = argc - 4;
	else
		children_data.total_commands = argc - 3;
	create_pipes(&children_data);
	validate(argv, children_data);
	validate_command(argv, envp, children_data);
	load_data(argc, argv, envp, &children_data);
	exec_children_process(children_data, argv, envp);
	last_command = valid_last_command(argv, envp, children_data.total_commands);
	if (!last_command)
	{	
		free(last_command);
		return (COMMAND_NOT_FOUND);
	}
	free(last_command);
	return (EXIT_SUCCESS);
}
