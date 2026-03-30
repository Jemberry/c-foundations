#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct node_s {
	char c1;
	char c2;
	char c3;
	char c4;
	char c5;

	//int i1;
	long long l1;
	//char c2;
	short s1;
}Node;


int main(void) {
	printf("%d\n", sizeof(Node));

	return 0;
}