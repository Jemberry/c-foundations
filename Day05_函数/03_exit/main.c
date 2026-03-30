#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1() {
	printf("test1---before.\n");
	//exit(1);
	//exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);

	// 代码为0  代码为1。 表明，程序是否正确退出。 

	EXIT_SUCCESS;
	EXIT_FAILURE;

	printf("test1---after.\n");
}


void test2() {
	// exit 在什么时候用，在学习阶段。 如果发现状况不对，可以使用
	// 但是在公司中，不建议使用。
}


int main(void) {
	test1();


	return 0;
}