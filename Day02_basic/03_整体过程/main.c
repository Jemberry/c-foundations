#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	printf("test1\n");
}

void test2();

int main(void) {
	test1();
	test2();

	return 0;
}