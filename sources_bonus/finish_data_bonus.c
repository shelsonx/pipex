/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:23:10 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/10 13:48:18 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	finish_data(t_data first_data, t_data last_data, int **fds)
{
	ft_free_tab(first_data.args);
	ft_free_tab(last_data.args);
	close_fds(fds);
	close(first_data.infile);
	close(last_data.outfile);
}

void	close_fds(int **fds)
{
	int	i;

	i = 0;
	while (fds[i])
	{
		close(fds[i][0]);
		close(fds[i][1]);
		i++;
	}
}
