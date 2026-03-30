#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// sizeof 可以用于计算一个类型占多大空间。 

	// sizeof(类型)
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(float));

	// sizeof(变量名) ： 可以计算一个变量，占多大空间
	long long num1 = 10L;
	printf("%d\n", sizeof(num1));

	// sizeof(表达式)
	printf("%d\n", sizeof(2+3));
	printf("%d\n", sizeof(2+3.4));
	printf("%d\n", sizeof(2+3.4f));
}


int main(void) {

	test1();

	return 0;
}