#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void test1() {
	// 在C语言中，指针就是地址。 指针可以存储一个变量的地址。 
	int num = 10;

	// 现在，想使用一个指针，指向这个int。 
	// 指针 名字 = &num;

	// 指针，分两块记忆。 一块是声明的时候，一块是其他时候。 
	int *p1 = &num; // 声明

	printf("%d\n", *p1); // 使用
	*p1 = 8888;

	printf("%d\n", *p1);
}

void test2() {
	// int num = 100;

	// num是一个变量，存储在一个位置。  4个字节。 

	// p1叫做指针变量，它也是一个变量。 这个变量，存地址的。 
	// p1自己也会占据一块空间。 
	// 指针变量里面存储的是，别人的地址。 
	// int *p1 = &num;
}

int main(void) {
	test1();

	return 0;
}