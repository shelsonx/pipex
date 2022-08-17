#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int	fd[2];
	//fd[0] = read
	//fd[1] = write
	if (pipe(fd) == -1)
	{
		printf("An error ocurred with openning the pipe \n");
		return (1);
	}
	pid_t pid;
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(1));
		printf("Go from child process= %d\n", y);
	}
	return (0);
}
