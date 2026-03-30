#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 野指针： 就是我们也不知道这个指针指向哪了。 
	// 第一种情况： 声明指针的时候，不初始化。 
	// 第二种情况： 初始化为整数。 
	int *p1;

	*p1 = 987;

	int *p2 = 1008611;

	*p2;

	// 野指针，要比空指针有害。 因为野指针，有时候能取回来数据
	// 有时候取不回来数据，有时候系统崩溃。、 

	// 野指针，是大家一定要避免的。 
}


int main(void) {

	return 0;
}