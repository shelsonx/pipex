#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("PID of ex2.c= %d\n", getpid());
	char	*args[] = {"Hello", "42", "SP", NULL};
	execv("./ex03", args);
	printf("Back to ex01.c");
	return (0);
}