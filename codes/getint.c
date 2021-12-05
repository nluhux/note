#include <stdio.h>

int getint(int *pn) {
	int c, sign;

	while (isspace(c = getch())) {
		;
	}
	if (!isdigit(c) && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
		
}

int main(void) {
	
}
