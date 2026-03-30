#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test3() {
	printf("test3 before.\n");
	printf("test3 after.\n");
}
void test2() {
	printf("test2 before.\n");
	test3();
	test3();
	printf("test2 after.\n");
}
void test1() {
	printf("test1 before.\n");
	test2();
	test3();
	printf("test1 after.\n");
}
int main(void) {
	printf("main before.\n");
	test1();
	test2();
	printf("main after.\n");
	return 0;
}