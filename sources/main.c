#include "pipex.h"

int main(int argc, char **argv)
{
	char **command;
	command = ft_split(argv[argc - 1], ' ');
	int x;
	while (command[x])
	{
		ft_printf("%s\n", command[x]);
		x++;
	}
	command[ft_len_rows_tab(command)] = NULL;
	ft_printf("rows= %d\n", ft_len_rows_tab(command));
}
