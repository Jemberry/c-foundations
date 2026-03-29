#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "test1.h"
#include "test2.h"

int main(void) {
	// 头文件一多，就容易出现。
	// 撞车的情况。 所以我们需要头文件保护性语法
	// 头文件保护性语法：
	// 如果引入了一次，就不要再引入第二次了。 


	struct  student s1;
	
	return 0;
}