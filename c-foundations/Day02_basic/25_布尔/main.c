#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void test1() {
	//bool flag = false;
	//int flag = 0;

	//char flag = 0;
	char flag = '0';

	// 在C语言中，要知道哪些为真，哪些为假。 

	// C将 值为0 视作假。 
	// 任何非零值都被视为true(真)
	// 任何零值都被视为false(假)

	if (flag) {
		printf("flag 为真.\n");
	}
	else {
		printf("flag 为假.\n");
	}
}

void test2() {
	// true  false
	// 其实就是一个宏定义。 
	// #define false 0
	// #define true  1
	// true;
}

int main(void) {
	test1();
	return 0;
}