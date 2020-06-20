#include <stdio.h>
#include <fcntl.h>

int main() {
	
	printf("Hello World\n");
	
	//create a file in c language: open(...);
	//open(...) function comes from standard c library
	
	int fd;
	//OWNER - GROUP - OTHER USERS
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP;
	char *filename = "/home/user01/myfile.txt";
	
	fd = open(filename, O_CREAT, mode);
		
	
	
	return 0;	
}

/*
 *Homework:
 *Extend the example with writing to the file using only system calls.
 * */
