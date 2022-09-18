/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_command_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:49:27 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/18 00:08:11 by sjhony-x         ###   ########.fr       */
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
		free(exec_command);
		exec_command = NULL;
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
	char **argv, char **envp, t_children_data children_data)
{
	int		i;
	int		additional;
	char	**command;
	char	*exec_command;
	
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		i = 3;
		additional = 2;
	}
	else
	{
		i = 2;
		additional = 1;
	}
	while (argv[i] && i <= (children_data.total_commands + additional))
	{
		valid_first_command(argv, envp, i);
		command = ft_split(argv[i], ' ');
		exec_command = valid_first_command(argv, envp, i);
		if (!exec_command)
			error_command_msg(command);
		free(exec_command);
		ft_free_tab(command);
		i++;
	}
}
