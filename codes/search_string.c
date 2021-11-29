#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int m_getline(char line[],int lim);
int m_strindex(char source[],char searchfor[],int si);
int m_strindexall(char source[],char searchfor[]);
void m_printf_posall(char line[]);
void test_m_strindexall(void);

int stack[MAXLINE]; // stack
int sp = 0; // stack pointer

int push(int n);
int pop(void);

int main(int argc, char *argv[]) {
	char *pattern = argv[1];
	char line[MAXLINE];

	while (m_getline(line,MAXLINE) > 0 ) {
		m_strindexall(line,pattern);
		m_printf_posall(line);
	}

	
//	test_m_strindexall();
}

void test_m_strindexall(void) {
	char *pattern = "Hello";
	char *line0 = "HelloWorldHelloWorldHelloWorldHelloWorldWOrldHelloAAA";
	char *line1 = "HelloWorldHelloWorldHelloWorldHlloWorldWOrldHelloAAA";
	char *line2 = "HelloWorldelloWorldHelloWorldHelloWorldWOrldHelloAAA";
	char *line3 = "HelloWorldHelloWorldHlloWorldHelloWorldWOrldHelloAAA";

	m_strindexall(line0,pattern);
	m_printf_posall(line0);
	m_strindexall(line1,pattern);
	m_printf_posall(line1);
	m_strindexall(line2,pattern);
	m_printf_posall(line2);
	m_strindexall(line3,pattern);
	m_printf_posall(line3);
}

int m_getline(char line[],int lim) {
	int i;
	int c;
	for (i = 0; lim > 0;i++,lim--) {
		c = getchar();
		if (c == EOF) {
			break;
		}
		if (c == '\n') {
			break;
		}
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

int m_strindex(char *s, char *t,int si) {
	int i, j, k;

	for (i=si; s[i] != '\0'; i++) {
		for (j=i, k=0;t[k] != '\0' && s[j] == t[k]; j++, k++ ) {
			;
		}
		if ( k > 0 && t[k] == '\0') {
			return i;
		}
	}
	return -1;
}

int m_strindexall(char *s, char *t) {
	int ret = 0;
	int count = 0;
	int i = 0;
	for (;;) {
		if (s[0] == '\0') {
			break;
		}
		if ((ret = m_strindex(s,t,i)) == -1) {
			break;
		}
		if (push(ret) == -1) {
			break;
		}
		i = ret + strlen(t);
		count++;
	}
	return count;
}


int push(int n) {
	if (sp < MAXLINE) {
		stack[sp] = n;
		sp++;
	} else {
		return -1;
	}
	return 0;
}

int pop(void) {
	if (sp > 0) {
		--sp;
		return stack[sp];
	} else {
		printf("stack empty\n");
		exit(1);
	}
}

void m_printf_posall(char line[]) {
	while (sp > 0) {
		printf("%d ",pop());
	}
	printf("\t | ");
	printf("%s",line);
}
