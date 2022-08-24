/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:05:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/24 14:25:38 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_command(char *str)
{
	char	**command;
	char 	*tmp;
	char	*set;
	
	int x = 0;
	while (str[x])
	{
		if (str[x] == 39 && str[x+1] == 32)
		{
			str[x] = 32;
			str[x+1] = 42;
		}
		else if (str[x] == 39 && str[x-1] == 32)
		{
			str[x] = 32;
			str[x-1] = 42;
		}
		x++;
	}
	command = ft_split(str, ' ');

	int i = 0;
	int y;
	while (command[i])
	{
		y = 0;
		while (command[i][y])
		{
			if (command[i][y] == 42)
				command[i][y] = 32;
			y++;
		}
		set = " ";
		if (i != 0)
			set = "\'";
		tmp = ft_strdup(command[i]);
		free(command[i]);
		command[i] = ft_strtrim(tmp, set);
		free(tmp);
		i++;
	}
	
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
	dup2(data.file_fd, data.first_redirect_std);
	close(data.file_fd);
	dup2(data.second_redirect_pipe, data.second_redirect_std);
	close(data.first_redirect_pipe);
	close(data.second_redirect_pipe);
	if (data.exec_command)
		execve(data.exec_command, data.args, NULL);
	free(data.exec_command);
}
