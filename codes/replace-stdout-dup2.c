#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_PERM_MODE (S_IRUSR | S_IWUSR)

int main(void) {
	int stdout_fd;
	int file_fd;
	
	printf("在向屏幕输出内容\n");
	
	stdout_fd = 3; // 定义stdout新的fd
	if (dup2(STDOUT_FILENO,stdout_fd) == -1) {
		perror("dup2() failed: ");
		exit(1);
	}
	
	if (close(STDOUT_FILENO)) {
		perror("close() failed: ");
		exit(1);
	}
	
	file_fd = open("/tmp/out",O_WRONLY | O_CREAT | O_TRUNC,FILE_PERM_MODE);
	if ( file_fd == -1) {
		perror("open() failed: ");
		exit(1);
	}

	printf("在向文件输出内容\n");

	if (close(STDOUT_FILENO)) {
		perror("close() failed: ");
		exit(1);
	}

	if (dup2(stdout_fd,STDOUT_FILENO) == -1) {
		perror("dup2() failed: ");
		exit(1);
	}
	if (close(stdout_fd)) {
		perror("close failed: ");
		exit(1);
	}
	printf("在向屏幕输出内容\n");

	exit(0);
}
