#include <stdio.h>

int main(void) {
	char *px = "123";
	printf("%d\n",*px);
	px += 1;
	printf("%d\n",*px);
	px += 1;
	printf("%d\n",*px);
	return 0;
}
