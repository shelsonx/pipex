/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:49:27 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/27 05:12:12 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*valid_command(char **command, char **envp)
{
	char	*exec_command;

	exec_command = get_exec_command(command[0], envp);
	if (!exec_command)
	{
		ft_printf("pipex: %s: command not found\n", command[0]);
		free(exec_command);
		ft_free_tab(command);
	}
	return (exec_command);
}

char	*valid_first_command(char **argv, char **envp)
{
	char	**first_command;

	first_command = create_command(argv[2]);
	return (valid_command(first_command, envp));
}

char	*valid_last_command(int argc, char **argv, char **envp)
{
	char	**last_command;

	last_command = create_command(argv[argc -2]);
	return (valid_command(last_command, envp));
}

void	validate_command(
	int argc, char **argv, char **envp, t_children_data children_data)
{
	if (!valid_first_command(argv, envp)
		&& valid_last_command(argc, argv, envp))
	{
		create_child_process(execute_command, children_data.last_data);
		finish_data(children_data.first_data, children_data.last_data,
			children_data.pipe_fd);
		exit(0);
	}
	if (!valid_last_command(argc, argv, envp))
	{
		finish_data(children_data.first_data, children_data.last_data,
			children_data.pipe_fd);
		exit(127);
	}
}
