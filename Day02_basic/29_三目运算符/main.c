#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 三目运算符： 就是一个可以判断条件的，如果条件为真，返回一个值。为假，返回另一个值

	int num = 987;

	// 如果num是奇数，res是100 ； 如果是偶数，res是200
	int res = 0;

	if (num % 2 == 0) {
		res = 200;
	}
	else {
		res = 100;
	}

	int res2 = num % 2 == 0 ? 200 : 100;
}


int main(void) {

	return 0;
}