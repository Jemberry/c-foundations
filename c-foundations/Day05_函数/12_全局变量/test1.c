#include <stdio.h>

// 全局变量不能同名。 
//int global_num666 = 100999;

// 这个就是，直接在全局找一个叫做 global_num666的全局变量。 
// 一定要使用 extern这个语法。 
extern int global_num666;

void test1111() {
	printf("66666 in test1111() in test1.c.\n");

	printf("global num666 = %d in test1.c\n", global_num666);

	global_num666 = 123456;
}