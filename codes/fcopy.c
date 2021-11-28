#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
	FILE *src;
	FILE *dest;
	char *srcfilename = argv[1];
	char *destfilename = argv[2];
	char buf[BUFSIZE];
	struct stat sb;
	mode_t file_perm_mode = 0;
	int n;

	if ((src = fopen(srcfilename,"r")) == NULL) {
		perror("fopen() failed: ");
		exit(1);
	}
	if (stat(srcfilename,&sb) == -1) {
		perror("stat() failed: ");
		exit(1);
	}
	file_perm_mode = sb.st_mode & 07777;
	if (access(destfilename,F_OK) != -1) {
		if (stat(destfilename,&sb) == -1) {
			perror("stat() failed: ");
			exit(1);
		}
	        if (S_ISDIR(sb.st_mode)) {
			fprintf(stderr,"dest file is directory\n");
			exit(1);
		} else if (unlink(destfilename) == -1) {
			perror("unlink() failed: ");
			exit(1);
		}
	}
	if (creat(destfilename,file_perm_mode) == -1) {
		perror("creat() failed: ");
		exit(1);
	}
	
	if ((dest = fopen(destfilename,"w+")) == NULL) {
		perror("fopen() failed: ");
		exit(1);
	}

	if (ftruncate(fileno(dest),0) == -1) {
		perror("ftruncate() failed: ");
		exit(1);
	}

	for (;;) {
		if ((n = fread(buf,1,BUFSIZE,src)) < 0) {
			perror("fread() failed: ");
			exit(1);
		}
		
		if (n == 0 ) {
			break;
		}
		
		if (fwrite(buf,1,n,dest) != n) {
			perror("fwrite() failed: ");
			exit(1);
		}
	}
	fclose(src);
	fclose(dest);
	exit(1);
}
