#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int fd[2];
	char	*command_1[] = {"/bin/tr", "D", "d", NULL};
	char	*command_2[] = {"/bin/head", "-6", NULL};
	pid_t pid1;
	pid_t pid2;

	int file_in = open("file_in", O_RDONLY);
	int file_out = open("file_out", O_WRONLY | O_CREAT, 0777);

	if (pipe(fd) < 0)
		return (1);

	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(file_in, STDIN_FILENO);
		close(file_in);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(command_1[0], command_1, NULL);
	}

	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(file_out, STDOUT_FILENO);
		close(file_out);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve(command_2[0], command_2, NULL);
	}
	close(fd[0]);
	close(fd[1]);
	close(file_in);
	close(file_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
