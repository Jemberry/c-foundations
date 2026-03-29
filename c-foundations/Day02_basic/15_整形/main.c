#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// C中的整形
	// short  int   long     long long 

	// 又可以整体分两类： 一种叫做有符号数，一种叫做无符号数。 

	// int : 占4个字节。 
	// 100000000000000000000000000000000001
	// 如果所有位，都用来表示数据， 这个就是无符号数。 
	// 如果最高位，用来表示正负， 这个就是有符号数。

	int num = -10;
}

void test2() {
	// 有符号数。 如果
	// 100000000000000000000000000000000001

	// 原补反。 
	// 这个先不用管。 
}

void test3() {
	// 无符号数，使用的时候，注意一下。 
	int num = -50;

	unsigned int num2 = 100;

	if (num > num2) {
		// 有符号数和无符号数进行计算，会将有符号数当做无符号数对待。 
		printf("num > num2\n");
	}
	else {
		printf("num < num2\n");
	}

}


int main(void) {

	test3();

	return 0;
}