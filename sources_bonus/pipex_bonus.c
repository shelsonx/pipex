/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:20 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/18 14:04:17 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	pipex(int argc, char **argv, char **envp)
{
	t_children_data	children_data;
	//int				i;
	char			*last_command;

	if(ft_strncmp(argv[1], "here_doc", 9) == 0)
		children_data.total_commands = argc - 4;
	else
		children_data.total_commands = argc - 3;
	create_pipes(&children_data);
	load_data(argc, argv, envp, &children_data);
	/* i = 2;
	while (i <= children_data.total_commands)
	{
		validate(argv, children_data, i);
		i++;
	} */
	validate_command(argv, envp, children_data);
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
