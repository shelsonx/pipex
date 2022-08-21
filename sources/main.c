#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	/* char **command;
	command = ft_split(argv[argc - 1], ' ');
	int x;
	while (command[x])
	{
		ft_printf("%s\n", command[x]);
		x++;
	}
	command[ft_len_rows_tab(command)] = NULL;
	ft_printf("rows= %d\n", ft_len_rows_tab(command)); */
	
	
	/* char	**command;
	int i = 0;
	command = create_command("tr D d");
	while (command[i])
	{
		ft_printf("%s\n", command[i]);
		i++;
	}
	ft_free_tab(command); */

	/* char	*exec_cmd;
	char	**command;

	command = create_command("echo");
	exec_cmd = get_exec_command(command[0], envp);
	ft_printf("%s\n", exec_cmd); */
	char *env_path = get_env_path(envp);
	char **paths = get_paths_cmds(env_path);
	
	int i = 0;
	while (paths[i])
	{
		ft_printf("%s\n", paths[i]);
		i++;
	}

}
