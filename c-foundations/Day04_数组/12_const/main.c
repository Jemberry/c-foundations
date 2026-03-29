#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// const 是一个关键字。我们可以认为，加了const关键字，就可以让
	// 一个变量，"看起来" 变成了 常量。 
	const int num = 999;

	// num = 987654;

	// 到底能否修改呢？ 可以被修改
}

void test2() {
	const int num = 9876;

	// num = 6655443;
	printf("num = %d\n", num);

	scanf("%d", &num);

	printf("num = %d\n", num);
}

void test3() {
	// 这个东西，const有什么用？
	// 可以帮助我们避免一些写错了的情况。 
	const int num1;
	int num2;
	int num3;
	int num4;
	int num5;

	//num1 = 987;
	// 用来做确认动作，不想每次都是靠肉眼记住。 

	//num1 = getchar();
}


int main(void) {

	test2();

	return 0;
}