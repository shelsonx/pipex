/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:29:16 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/03 21:31:34 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parser_arg(char *arg)
{
	int	x;

	x = 0;
	while (arg[x])
	{
		if (arg[x] == '\'' && arg[x +1] == ' ')
		{
			arg[x] = ' ';
			arg[x +1] = '*';
		}
		else if (arg[x] == '\'' && arg[x -1] == ' ')
		{
			arg[x] = ' ';
			arg[x -1] = '*';
		}
		x++;
	}
}

void	parser_command(char **command)
{
	int		i;
	int		y;
	char	*set;
	char	*tmp;

	i = 0;
	while (command[i])
	{
		y = 0;
		while (command[i][y])
		{
			if (command[i][y] == '*')
				command[i][y] = ' ';
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
}
