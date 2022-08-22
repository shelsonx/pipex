/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 07:35:49 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/22 03:03:08 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libs/libft/libft.h"

typedef struct s_data
{
	int		file_fd;
	int		first_redirect_pipe;
	int		second_redirect_pipe;
	int		first_redirect_std;
	int		second_redirect_std;
	char	*exec_command;
	char	**args;
}	t_data;

//COMMAND
char	**create_command(char *str);
char	*join_path_command(char *path, char *command);
char	*get_exec_command(char *command, char **envp);
void	execute_command(t_data data);

//PATH
char	*get_env_path(char **envp);
char	**get_paths_cmds(char *env_path);
void	get_path(char **envp);

//CHILD PROCESSS
pid_t	create_child_process(void (*func)(t_data), t_data data);

//INIT_DATA
t_data	get_data_first_cmd(char **argv, char **envp, int *fd);
t_data	get_data_last_cmd(int argc, char **argv, char **envp, int *fd);

#endif