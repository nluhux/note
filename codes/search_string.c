#include <stdio.h>

/* 无法正常工作 */

#define MAXLINE 1000

int m_getline(char line[],int lim);
int m_strindex(char source[],char searchfor[]);
int recur_m_strindex(char source[],char searchfor[], int si);
int recur_m_printf_pos(char line[]);

int stack[MAXLINE];

void push(int n);
int pop();

int main(int argc, char *argv[]) {
	char *pattern = argv[1];
	char line[MAXLINE];
	char stack[MAXLINE];
	int instacknum = 0;
	int found = 0;
	int pos = 0;

	while (m_getline(line,MAXLINE) > 0 ) {
		recur_m_strindex(line,pattern,0);
		recur_m_printf_pos(line);
	}

	return found;
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
		i++;
		line[i] = c;
	}
	line[i] = '\0';
	return i;
}

int m_strindex(char s[], char t[], int si) {
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

int recur_m_strindex(char s[], char t[],int si) {
	int ret = 0;
	ret = m_strindex(s,t,si);
	if (ret != -1) {
		push(ret);
		return (recur_m_strindex(s,t,ret));
	} else {
		return -1;
	}
}


void push(int n) {
	int i;
	for(i = 0;stack[i] != '\0';i++);
	stack[i] = n;
	i++;
	stack[i] = '\0'
}

int pop() {
	int i;
	int n;
	for(i = 0;stack[i] != '\0';i++);
	n = stack[i];
	stack[i] = '\0';
        return n;
}

int recur_m_printf_pos(char line[]) {
	
	printf
}
