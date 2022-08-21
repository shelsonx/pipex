#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libs/libft/libft.h"

//COMMAND
char	**create_command(char *str);
char	*join_path_command(char *path, char *command);
char	*get_exec_command(char *command, char **envp);

//PATH
char	*get_env_path(char **envp);
char	**get_paths_cmds(char *env_path);
void	get_path(char **envp);
#endif