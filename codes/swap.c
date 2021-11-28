#include <stdio.h>

void swapint(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main(void) {
	int a = 'a';
	int b = 'b';
	printf("before swap: a = %c, b = %c\n",a,b);
	swapint(&a,&b);
	printf("after swap: a = %c, b = %c\n",a,b);
	return 0;
}
