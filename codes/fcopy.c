#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
	FILE *src = NULL;
	FILE *dest = NULL;
	char buf[BUFSIZE];
	int n;

	if ((src = fopen(argv[1],"r")) == NULL) {
		perror("fopen() failed: ");
		exit(1);
	}
	
	if ((dest = fopen(argv[2],"w+")) == NULL) {
		perror("fopen() failed: ");
		exit(1);
	}

	// 截断文件
	if (ftruncate(fileno(dest),0) == -1) {
		perror("ftruncate() failed: ");
		exit(1);
	}

	for (;(n = fread(buf,1,BUFSIZE,src)) > 0;) {
		if (fwrite(buf,1,n,dest) != n) {
			perror("fwrite() failed: ");
			exit(1);
		}
	}
	fclose(src);
	fclose(dest);
	exit(1);
}
