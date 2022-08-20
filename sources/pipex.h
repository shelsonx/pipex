#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libs/libft/libft.h"

//COMMAND
char	**create_command(char *str);
char	*join_path_command(char *path, char *command);
#endif