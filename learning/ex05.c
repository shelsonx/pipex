#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	pid_t id_1 = fork();
	pid_t id_2 = fork();

	if (id_1 == 0)
	{
		if (id_2 == 0)
			printf("We are process y\n");
		else
			printf("We are process x\n");
	}
	else
	{
		if (id_2 == 0)
			printf("We are process z\n");
		else
			printf("We are the parent process\n");
	}

	while (wait(NULL) != -1 || errno != ECHILD)
		printf("Waited for a child to finish\n");
}
