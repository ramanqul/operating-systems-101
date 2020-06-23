#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>


/*
 *How to compile: gcc -o producer producer.c -lrt
 *
 * */

int main() {

	const int SIZE = 4096;
	const char* name = "OS";
	const char* message_0 = "Hello";
	const char* message_1 = "World";

	int shm_fd;

	void* shared;

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

	ftruncate(shm_fd, SIZE);

	shared = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

	sprintf(shared, "%s", message_0);
	shared += strlen(message_0);
	sprintf(shared, "%s", message_1);
	shared += strlen(message_1);

	return 0;
}
