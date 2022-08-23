//FALTA INCLUIR O HEADER DA 42

#include "pipex.h"

void	validate_empty_args(char *arg)
{
	int		i;
	size_t	count_space;

    if (arg[0] == '\0')
        exit(0);
	i = 0;
	count_space = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			count_space++;
		i++;
	}
	if (count_space == ft_strlen(arg))
	{
		ft_printf("pipex: %s: command not found\n", arg);
		exit(0);
	}
}
