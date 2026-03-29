#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int global_num666 = 1008611;
//static int global_num666 = 1008611;

int global_num777;

int main(void) {

	test1111();

	printf("global print in main.c = %d\n", global_num666);

	printf("global_num777 = %d\n", global_num777);

	return 0;
}