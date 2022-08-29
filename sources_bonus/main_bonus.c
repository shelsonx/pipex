/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:27:11 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/27 14:36:43 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_printf("Invalid arguments!\n");
		exit(EXIT_FAILURE);
	}
	else
		pipex(argc, argv, envp);
	return (0);
}
