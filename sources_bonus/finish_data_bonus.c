/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:23:10 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/03 21:28:24 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	finish_data(t_data first_data, t_data last_data, int *fd)
{
	ft_free_tab(first_data.args);
	ft_free_tab(last_data.args);
	close(fd[0]);
	close(fd[1]);
	close(first_data.file_fd);
	close(last_data.file_fd);
}
