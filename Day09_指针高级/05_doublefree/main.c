#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1() {
	// 什么叫做double free 
	// 就是同样一块内存，free释放了两次。 

	int *p = malloc(40);


	// 
	// 

	free(p);
	free(p);
}


void test2() {
	int *p = malloc(40);

	test3(p);

	// test4(p)
	//      test4函数内部，free了

	free(p);
}


int main(void) {

	return 0;
}