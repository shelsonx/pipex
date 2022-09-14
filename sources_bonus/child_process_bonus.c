/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 05:41:02 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/14 17:17:43 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

pid_t	create_child_process(void (*func)(t_data, t_children_data), t_data data,
			t_children_data children_data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		func(data, children_data);
	}
	return (pid);
}
