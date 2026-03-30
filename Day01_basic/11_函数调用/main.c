#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int test1() {
	printf("test1---------.\n");
	return 100;
}

int main(void) {

	//int res = test1();
	int res = test1; // 函数的地址。如果直接写函数名，不写 () 
	printf("%d\n", res);

	return 0;
}