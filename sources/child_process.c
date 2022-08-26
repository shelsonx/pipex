/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 05:41:02 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/26 21:28:29 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	create_child_process(void (*func)(t_data), t_data data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		error(ECHILD);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		func(data);
	}
	return (pid);
}
