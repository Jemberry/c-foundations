#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {

	// 推荐大家使用这种方式， 不使用下面这种。 
	// 因为C中，一行可以定义多种数据类型。 
	int *p1;

	int* p2;//不推荐这种写法， 容易产生误解。 

	//int *p1, arr[10], num2;

	//int* p1, p2, p3;
}

void test2() {
	// 其实更好的一种方式。 
	// int* p2;

	//int[10] array;
	//int arr[10];
	// 工业语言都是为了追求向前兼容性，不会随意动特性。 
}

void test3() {
	// 指针声明： 建议大家不要用int指针，指double

	double d1 = 10.2;

	int *p1 = &d1;

	// 使用int指针，指int
	// 使用double指针，指double

	int *p3;
}

int main(void) {

	return 0;
}