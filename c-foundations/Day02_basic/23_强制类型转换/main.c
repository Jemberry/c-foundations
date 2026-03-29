#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	int num1 = 10;

	//short s1 = num1;
	short s1 = (short)num1;

	// 编译器，会担心你是不是写错了。 
	// 在后续，有可能编译器，会直接拒绝这个隐式转换，要求你使用强制类型。
	// 强制类型转换，表明，程序员是知道这个转换的，他对这块的风险了解。 
}


int main(void) {

	return 0;
}