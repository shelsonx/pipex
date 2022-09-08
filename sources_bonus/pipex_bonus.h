/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 07:35:49 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/08 13:16:26 by sjhony-x         ###   ########.fr       */
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

# define COMMAND_NOT_FOUND 127
# define STDERR 2

typedef struct s_data
{
	int		**fd;
	int		fd_in;
	int		fd_out;
	int		infile;
	int		outfile;
	int		second_pipe;
	char	*exec_command;
	char	**args;
}	t_data;

typedef struct s_children_data
{
	t_data	first_data;
	t_data	middle_data;
	t_data	last_data;
	pid_t	first_pid;
	pid_t	middle_pid;
	pid_t	last_pid;
	int		**pipe_fd;
}	t_children_data;

//COMMAND
char	**create_command(char *str);
char	*join_path_command(char *path, char *command);
char	*get_exec_command(char *command, char **envp);
void	execute_command(t_data data);
void	close_fds(int **fds);

//PATH
char	*get_env_path(char **envp);
char	**get_paths_cmds(char *env_path);
void	get_path(char **envp);

//CHILD PROCESSS
pid_t	create_child_process(void (*func)(t_data), t_data data);

//INIT_DATA
t_data	get_data_first_cmd(char **argv, char **envp, int **fd);
t_data	get_data_last_cmd(int argc, char **argv, char **envp, int **fd);
t_data	get_data_middle_cmd(char **argv, char **envp, int **fd);

//FINISH DATA
void	finish_data(t_data first_data, t_data last_data, int **fd);

//PIPEX
int		pipex(int argc, char **argv, char **envp);

//VALIDATE COMMAND
void	validate_command(int argc, char **argv, char **envp,
			t_children_data children_data);
char	*valid_first_command(char **argv, char **envp);
char	*valid_last_command(int argc, char **argv, char **envp);

//VALIDATE ARGS
void	validate_empty_args(char *command);

//PARSER
void	parser_arg(char *arg);
void	parser_command(char **command);

//VALIDATE FDs FILES
void	validate_fd_files(t_data first_data, t_data last_data,
			char **argv, int *pipe_fd);

//VALIDATE
void	validate(
			int argc, char **argv, char **envp, t_children_data children_data);

//EXECUTE CHILDREN PROCCESS
void	exec_children_process(t_children_data children_data);

//LOAD DATA
void	load_data(
			int argc, char **argv, char **envp, t_children_data *children_data);

#endif