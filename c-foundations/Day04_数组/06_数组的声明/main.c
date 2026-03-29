#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INIT_LEN 90

void test1() {
	int arr[5];
	char arr2[8];
}

void test2() {
	// 数组声明时候，中括号中，只能写常量。 
	int arr1[8];

	const int len = 10;
	//int arr2[len];

	int arr3[INIT_LEN];
}

void test3() {
	// 从C99开始，变长数组是允许的。  但是不建议使用。
	int len = 10;
	//int arr2[len];
}

void test4() {
	int arr1[8];
}


int main(void) {
	//int num = 10;
	//num = 888;

	test4();
	return 0;
}