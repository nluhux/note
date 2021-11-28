#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int m_getline(char line[], int lim);
int m_rstrindex(char s[], char t[]);

int main(int argc, char *argv[]) {
	char *pattern = argv[1];
	char line[MAXLINE];
	int count  = 0;
	int len = 0;
	int pos = 0;

	for (;(len = m_getline(line,MAXLINE)) > 0;) {
		if ((pos = m_rstrindex(line,pattern)) != -1) {
			printf("%d : %s",pos,line);
			count++;
		}
	}
	exit(count);
}

int m_getline(char line[], int lim) {
	int i = 0;
	int c;
	for (;lim > 0;lim--,i++) {
		c = getchar();
		if ( c == EOF || c == '\n' ) {
			break;
		}
		line[i] = c;
	}
        if ( c == '\n') {
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

int m_rstrindex(char t[], char s[]) {
	int ei = strlen(t)-1;
	int s_len = strlen(s);
	int j,k;
	for (;ei >= 0;ei--) {
		for (j=ei,k=0;;j++,k++) {
			if (!(t[j] == s[k])) {
				break;
			}
			if (t[j] != s[k] && t[j] == '\0') {
				break;
			}
			if (k == (s_len-1)) {
				return ei;
			}
		}
	}
	return -1;
}

