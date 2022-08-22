/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:27:11 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/22 16:29:21 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_printf("Invalid arguments!\n");
		exit(1);
	}
	else
	{
		validate_command(argc, argv, envp);
		pipex(argc, argv, envp);
	}
	return (0);
}
