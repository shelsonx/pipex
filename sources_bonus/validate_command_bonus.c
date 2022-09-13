/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_command_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:49:27 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/13 04:47:23 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_command_msg(char **command)
{
	char	*msg;
	char	*tmp;

	tmp = ft_strjoin("pipex: ", command[0]);
	msg = ft_strjoin(tmp, ": command not found\n");
	write(STDERR, msg, ft_strlen(msg));
	free(tmp);
	free(msg);
}

char	*valid_command(char **command, char **envp)
{
	char	*exec_command;

	exec_command = get_exec_command(command[0], envp);
	if (!exec_command)
	{
		error_command_msg(command);
		free(exec_command);
		ft_free_tab(command);
	}
	return (exec_command);
}

char	*valid_first_command(char **argv, char **envp, int i)
{
	char	**first_command;

	first_command = create_command(argv[i]);
	return (valid_command(first_command, envp));
}

char	*valid_last_command(char **argv, char **envp, int i)
{
	char	**last_command;
	last_command = create_command(argv[i +1]);
	return (valid_command(last_command, envp));
}

void	validate_command(
	char **argv, char **envp, t_children_data children_data, int i)
{
	char	*first_command;
	char	*last_command;

	first_command = valid_first_command(argv, envp, i);
	if (i <= children_data.total_commands)
		last_command = valid_last_command(argv, envp, i);
	if (!first_command && last_command)
	{
		if (i < children_data.total_commands)
			create_child_process(execute_command, children_data.middle_data, children_data);
		else
			create_child_process(execute_command, children_data.last_data, children_data);
		/* finish_data(children_data.first_data, children_data.last_data,
			children_data.pipe_fd); */
		exit(COMMAND_NOT_FOUND);
	}
}
