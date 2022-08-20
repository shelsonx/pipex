/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:19:11 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/20 05:36:00 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env_path(char **envp)
{
	char	*env_path;
	int		i;

	i = 0;
	while (envp[i])
	{
		env_path = ft_strnstr(envp[i], "PATH", ft_strlen(envp[i]));
		if (env_path)
			return (env_path);
		i++;
	}
	return (env_path);
}

char	**get_paths_cmds(char *env_path)
{
	char	*sub_path;
	char	**paths;

	sub_path = ft_substr(env_path, 5, ft_strlen(env_path));
	paths = ft_split(sub_path, ':');
	return (paths);
}

void	get_path(char **envp)
{
	char	**dirs;
	char 	*env_path = get_env_path(envp);
	
	dirs =  get_paths_cmds(env_path);

	int i = 0;
	while (dirs[i])
	{
		ft_printf("%s\n", dirs[i]);
		i++;
	}
}