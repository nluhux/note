#include <stdio.h>
#include "stack.c"

int main(void) {
	int i = 0;
	for (i=0;i<200;i++) {
		push(i);
	}
	for (i=0;i<200;i++) {
		printf("%f",pop());
	}
	return 0;
}
