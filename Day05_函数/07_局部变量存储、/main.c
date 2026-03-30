#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void test1() {
	int a = 10;
	int b = 20;
	printf("test1---%d\n", a);
	printf("test1---%d\n", b);
	//printf("test1---%d\n", c);
}

int main(void) {
	// 局部变量，存储在栈帧中。 
	int a = 1;
	int b = 2;
	int c = 3;
	printf("main---%d\n", a);
	printf("main---%d\n", b);
	printf("main---%d\n", c);
	test1();
	printf("main---%d\n", a);
	printf("main---%d\n", b);
	printf("main---%d\n", c);

	return 0;
}