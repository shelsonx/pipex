#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char *args[] = {"/bin/ls", "-la", NULL};
	int file = open("out.txt", O_WRONLY | O_CREAT, 0777);
	if (file == -1)
		return (1);
	dup2(file, STDOUT_FILENO);
	close(file);
	execve(args[0], args, NULL);
	return (0);
}
