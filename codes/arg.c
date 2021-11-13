#include <stdio.h>
#include <unistd.h>

#define PROGNAME "demo"
#define VERSION "0.4"

void printf_version(void) {
	printf(PROGNAME);
	putchar(' ');
	printf(VERSION);
	putchar('\n');
}

void usage(void) {
	printf(PROGNAME);
	putchar(' ');
	printf("filename");
	putchar('\n');
}

void nop(void) {
	;
}

int main(int argc, char *argv[]) {
	int opt;
	if (argc < 2) {
		usage();
		return 1;
	}
	for (;(opt = getopt(argc, argv, "nhv")) != -1;) {
		switch (opt) {
		case 'n':
			nop();
		case 'h':
			usage();
		case 'v':
			printf_version();
		default:
			usage();
		}
		printf("opt: %c\t",opt);
		printf("optind: %d\t",optind);
		putchar('\n');
	}
}
