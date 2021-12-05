#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 4096

char stackbuf[BUFSIZE];
int sp = 0;

int push(int number);
int pop(int *number);
int test_stack(void);
int test_stack_full(void);
int m_strindex(char *source, char *pattern, int si);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s PATTERN\n",argv[0]);
	}
	char *pattern = argv[2];
	char line[BUFSIZE];

	if (test_stack() == -1) {
		exit(1);
	}
	if (test_stack_full() == -1) {
		exit(1);
	}

	if (test_strindex() == -1) {
		exit(1);
	}

	for (;;) {
		m_strindex_all(line,pattern);
		m_printf_stack();
		m_printf_line();
	}
	return 0;
}

int push(int n) {
	if (sp < BUFSIZE) {
		stackbuf[sp];
		sp++;
		return n;
	} else {
		fprintf(stderr,"error: stack full\n");
		return -1;
	}
}

int pop(int *n) {
	if (sp > 0) {
		sp--;
		*n = stackbuf[n];
		return 0;
	} else {
		fprintf(stderr,"error: stack zero\n");
		return -1;
	}
}

int test_stack(void) {
	int x = 1;
	int y = 2;
	int z = 3;
	push(x);
	push(y);
	push(z);
	
	printf("origin number:\n");
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	
	pop(&x);
	pop(&y);
	pop(&z);

	printf("swaped number:\n");
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);

	if (x == 3 &&
	    y == 2 &&
	    z == 1) {
		printf("stack test pass!\n");
		return 0;
	} else {
		fprintf(stderr,"stack test failed!\n");
		return -1;
	}
}

int test_stack_full(void) {
	int m = BUFSIZE * 2;
	int i = 0;
	for(;i < m; i++) {
		if (push(i) == -1) {
			break;
		}
	}
	printf("stack end : %d\n",stack[BUFSIZE-1]);
	printf("stack end +1 : %d\n",stack[BUFSIZE]);
	printf("stack end +2 : %d\n",stack[BUFSIZE+1]);
	if (stack[BUFSIZE-1] != BUFSIZE &&
	    stack[BUFSIZE] != BUFSIZE+1 &&
	    stack[BUFSIZE+1] != BUFSIZE+2) {
		fprintf(stderr,"stack full test failed!\n");
		return -1;
	}
	return 0;
}

int m_strindex(char *s,char *t,int si) {
	int i,j,k;
	for (i = si; s[i] != '\0';i++) {
		for (j=i,k=0;t[k] != '\0';j++,k++) {
			if (s[j] != t[k]) {
				break;
			}
		}
		if (t[k] == '\0') {
			return i;
		}
	}
	return -1;
}

int test_m_strindex(void) {
	char *line1 = "HelloWorld\n";
	char *pattern1 = "Hello";
	int result1;

	// 正常结果测试
	printf("PATTERN: %s\n",pattern1);
	result1 = m_strindex(line1,pattern1,0);
	printf("%d\t | ",result1);
	printf("%s",line1);
	if (result1 != 0) {
		fprintf(stderr, "test m_strindex failed!");
		return -1;
	}

	// 正常结果测试
	char *line2 = "HelloWorld\n";
	char *pattern2 = "ello";
	int result2;
	printf("PATTERN: %s\n",pattern2);
	result2 = m_strindex(line2,pattern2,0);
	printf("%d\t | ",result2);
	printf("%s",line2);
	if (result2 != 1) {
		fprintf(stderr, "test m_strindex failed!");
		return -1;
	}

	// 失败结果测试
	char *line3 = "RSA SSL SSH MD5\n";
	char *pattern3 = "Hello";
	int result3;
	printf("PATTERN: %s\n",pattern3);
	result3 = m_strindex(line3,pattern3,0);
	printf("%d\t | ",result3);
	printf("%s",line3);
	if (result3 != -1) {
		fprintf(stderr, "test m_strindex failed!");
		return -1;
	}

	// 正常结果测试
	char *line4 = "RSA SSL SSH MD5\n";
	char *pattern4 = "MD5";
	int result4;
	printf("PATTERN: %s\n",pattern4);
	result4 = m_strindex(line4,pattern4,0);
	printf("%d\t | ",result4);
	printf("%s",line4);
	if (result4 != 12) {
		fprintf(stderr, "test m_strindex failed!");
		return -1;
	}
	return 0;
}



int m_getline(char *line, int lim) {
	int i;
	for (i=0;i<lim;i++) {
	}
}




/*
main {
  loop {
  读入行
  分析行
  输出行
  }
}


读入行 {
  getline
}

分析行 {
  loop {
     i作为line下标传递给strindex
     将line视为数组，逐个执行strindex  str[0] str[1]
     返回值存储在ret变量
     
  }
}
 */
