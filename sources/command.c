/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:05:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/20 15:15:12 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_command(char *str)
{
	char	**command;

	command = ft_split(str, ' ');
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
