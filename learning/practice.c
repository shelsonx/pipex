#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	//fd 0 read
	//fd 1 write

	int fd[2];
	pid_t pid;
	int file = open("out.txt", O_WRONLY | O_CREAT, 0777);

	if (pipe(fd) == -1)
	{
		printf("An error ocurrer with openning pipe");
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		int x;
		printf("Enter a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		dup2(file, STDOUT_FILENO);
		printf("Go from child process %d\n", y * 2);
	}
	return (0);
}