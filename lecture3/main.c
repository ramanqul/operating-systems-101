#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {

	pid_t pid;

	pid = fork();

	if (pid < 0) {
		printf("Error occured during process fork\n");
		return 1;
	} else if (pid == 0) {
		execlp("/home/user01/operating-systems-101/lecture2/main", "main", NULL);
	} else {
		wait(NULL);
		printf("Child complete");
	}

	return 0;
}
