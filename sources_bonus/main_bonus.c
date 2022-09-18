/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:27:11 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/18 18:50:39 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		ft_printf("Invalid arguments!\n");
		exit(EXIT_FAILURE);
	}
	else if (ft_strncmp(argv[1], "here_doc", 9) == 0 && argc < 6)
	{
		{
			ft_printf("Invalid arguments!\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		return (pipex(argc, argv, envp));
}
