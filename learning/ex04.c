#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t pid;
	int	n;

	pid = fork();
	if (pid == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
	if (pid != 0)
	{
		wait(NULL);
	}
	for (int i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	return (0);
}