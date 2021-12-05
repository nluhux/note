#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define FILE_PERM_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char *argv[]) {
	int stdout_fd;

	printf("正在往stdout输出内容\n");
	
	stdout_fd = dup(STDOUT_FILENO);
	if (stdout_fd == -1) {
		perror("dup() failed: ");
		exit(1);
	}
	close(STDOUT_FILENO);
	
	if (open("/tmp/abc",O_WRONLY | O_CREAT | O_TRUNC,FILE_PERM_MODE) == -1) {
		perror("open() failed: ");
		exit(1);
	}

	printf("已经把stdout重定向到文件\n");

	close(STDOUT_FILENO);
        if (dup(stdout_fd) == -1) {
		perror("dup() failed: ");
		exit(1);
	}
	close(stdout_fd);

	printf("我又回来了\n");
	
	exit(0);
}
