#include <stdio.h>
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if (sp < MAXVAL) {
		sp++;
		val[sp] = f;
	} else {
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop(void) {
	if (sp > 0) {
		--sp;
		return val[sp];
	} else {
		printf("error:stack empty\n");
		return 0.0;
	}
}
