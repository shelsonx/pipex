//FALTA INCLUIR O HEADER DA 42

#include "pipex.h"

void	validate_empty_args(char *command)
{
	int		i;
	size_t	count_space;

    if (command[0] == '\0')
        exit(0);
	i = 0;
	count_space = 0;
	while (command[i])
	{
		if (command[i] == ' ')
			count_space++;
		i++;
	}
	if (count_space == ft_strlen(command))
	{
		ft_printf("pipex: %s: command not found\n", command);
		exit(0);
	}
}
