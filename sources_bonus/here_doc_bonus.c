/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:51:38 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/14 17:08:29 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	is_limiter(char *line, char *limiter)
{
	return (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
		&& (ft_strlen(line) -1) == ft_strlen(limiter));
}

static void	exit_read(int **fd, char *line)
{
	free(line);
	close(1);
	close(2);
	close(fd[0][1]);
}

void	here_doc(int **fd, char *limiter)
{
	char	*line;

	while (TRUE)
	{
		ft_printf("here_doc> ");
		line = ft_get_next_line(STDIN_FILENO);
		if (is_limiter(line, limiter))
		{
			exit_read(fd, line);
			break ;
		}
		write(fd[0][1], line, ft_strlen(line));
		free(line);
	}
	free(line);
}
