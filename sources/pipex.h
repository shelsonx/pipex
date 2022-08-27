/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 07:35:49 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/27 03:30:17 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
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

//FINISH DATA
void	finish_data(t_data first_data, t_data last_data, int *fd);

//PIPEX
int		pipex(int argc, char **argv, char **envp);

//VALIDATE COMMAND
void	validate_command(int argc, char **argv);
char	*valid_first_command(char **argv, char **envp);
char	*valid_last_command(int argc, char **argv, char **envp);

//VALIDATE ARGS
void	validate_empty_args(char *command);

//ERROR
void	error(int error_num);

//PARSER
void	parser_arg(char *arg);
void	parser_command(char **command);

#endif