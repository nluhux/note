#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static int verbose = 0;

void _debug(const char *pfx, const char *msg, va_list ap) {
	if (pfx) {
		fprintf(stderr, "%s", pfx);
	}
	vfprintf(stderr,msg,ap);
	fprintf(stderr,"\n");
}

void die(const char *msg, ...) {
	va_list ap;
	va_start(ap, msg);
	_debug("[!] ", msg, ap);
	va_end(ap);

	exit(1);
}

void debug(const char *msg, ...) {
	va_list ap;
	if (!verbose)
		return;
	
	va_start(ap, msg);
	_debug("[+] ", msg, ap);
        va_end(ap);
}

void error(const char *msg, ...) {
	va_list ap;
	va_start(ap,msg);
	_debug("[-] ", msg, ap);
	va_end(ap);
}

int main(void) {
	verbose = 1;

	error("Hello" "World");
	debug("Hello" "World");

	die("Hello" "World");
	exit(0);
}
