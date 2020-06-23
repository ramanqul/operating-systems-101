#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>

/*
 *How to compile: gcc -o consumer consumer.c -lrt
 *
 * */

int main() {
	const int SIZE = 4096;
	const char *name = "OS";
	int shm_fd;

	void *shared;

	shm_fd = shm_open(name, O_RDONLY, 0666);

	shared = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

	printf("%s", (char *)shared);

	shm_unlink(name);

	return 0;
}
