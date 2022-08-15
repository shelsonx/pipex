#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("Hello 42SP!\nPID = %d\n", getpid());
}