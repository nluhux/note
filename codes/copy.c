#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TYPE_MASK 07777
#define BUFSIZE 4096

int main(int argc, char *argv[]) {
	char *src = argv[1];
	char *dest = argv[2];
	int infd = 0;
	int outfd = 0;
	char buf[BUFSIZE];
	struct stat sb;
	ssize_t n = 0; 
	int file_perm = 0;
	
	if ((infd = open(src, O_RDONLY)) == -1) {
		perror("open() failed: ");
		exit(1);
	}
	if (fstat(infd,&sb) == -1) {
		perror("fstat() failed: ");
		exit(1);
	}
	if (!S_ISREG(sb.st_mode)) {
		fprintf(stderr,"src is not regular file\n");
		exit(1);
	}
	file_perm = sb.st_mode & TYPE_MASK;
	if (access(dest,F_OK) != -1 ) {
		if (stat(dest,&sb) == -1) {
			perror("fstat() failed: ");
			exit(1);
		}
		if (S_ISDIR(sb.st_mode)) {
			fprintf(stderr,"dest is a directory\n");
			exit(1);
		} else if (unlink(dest) == -1) {
			perror("unlink() failed: ");
			exit(1);
		}
	}
	if ((outfd = open(dest,
			  O_WRONLY | O_CREAT | O_EXCL
			  ,file_perm)) == -1) {
		perror("open() failed: ");
		exit(1);
	}
	if (ftruncate(outfd,0) == -1) {
		perror("ftruncate() failed: ");
		exit(1);
	}
	for (;;) {
		if ((n = read(infd,buf,BUFSIZE)) == -1) {
			perror("read() failed: ");
			exit(1);
		}
		if (write(outfd,buf,n) == -1) {
			perror("write() failed: ");
			exit(1);
		}
		if (n == 0) {
			break;
		}
	}
	close(infd);
	close(outfd);
	exit(0);
}
