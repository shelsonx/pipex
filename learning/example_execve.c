#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char	*argv[] = {"/bin/ls", "-la", NULL};
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		int ret = execve(argv[0], argv, NULL);
		if (ret == -1)
			perror("ERROR");
	}
	else
	{
		wait(NULL);
		printf("Done with execve\n");
	}
}
