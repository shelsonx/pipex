#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	pid = fork();

	if (pid == 0)
		printf("I am child process\n");
	else
		printf("I am parent process\n");
	return (0);
}
