/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:05:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/20 02:58:55 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_command(char *str)
{
	char	**command;

	if (!str)
		return (NULL);
	command = ft_split(str, ' ');
	return (command);
}

char	*join_path_command(char *path, char *command)
{
	char	*full_path;

	full_path = ft_strjoin(path, command);
	return (full_path);
}
