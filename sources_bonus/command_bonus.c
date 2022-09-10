/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:05:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/10 19:17:43 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**create_command(char *str)
{
	char	**command;

	parser_arg(str);
	command = ft_split(str, ' ');
	parser_command(command);
	return (command);
}

char	*join_path_command(char *path, char *command)
{
	char	*full_path;
	char	*path_tmp;

	path_tmp = ft_strjoin(path, "/");
	full_path = ft_strjoin(path_tmp, command);
	free(path_tmp);
	return (full_path);
}

char	*get_exec_command(char *command, char **envp)
{
	char	*exec_command;
	char	**paths;
	char	*env_path;
	int		i;

	env_path = get_env_path(envp);
	paths = get_paths_cmds(env_path);
	i = 0;
	while (paths[i])
	{
		exec_command = join_path_command(paths[i], command);
		if (access(exec_command, X_OK) == 0)
		{
			ft_free_tab(paths);
			return (exec_command);
		}
		free(exec_command);
		exec_command = NULL;
		i++;
	}
	ft_free_tab(paths);
	return (NULL);
}

void	execute_command(t_data data)
{
	dup2(data.fd_in, STDIN_FILENO);
	dup2(data.fd_out, STDOUT_FILENO);
	//close(data.fd_in);
	//close(data.fd_out);
	close_fds(data.fd);
	if (data.exec_command)
		execve(data.exec_command, data.args, NULL);
	free(data.exec_command);
}
