/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:51:38 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/18 16:57:26 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	is_limiter(char *line, char *limiter)
{
	return (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
		&& (ft_strlen(line) -1) == ft_strlen(limiter));
}

void	here_doc(int **fd, char *limiter)
{
	char	*line;
	int		fd2;

	fd2 = dup(0);
	while (TRUE)
	{
		ft_printf("here_doc> ");
		line = ft_get_next_line(fd2);
		if (is_limiter(line, limiter))
		{
			free(line);
			close(fd2);
			close(1);
			close(fd[0][1]);
			line = ft_get_next_line(fd2);
			break ;
		}
		write(fd[0][1], line, ft_strlen(line));
		free(line);
	}
	free(line);
}
