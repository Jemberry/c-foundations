#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 数组名，在两种情况下，不能当做首元素指针看。 
	// sizeof的时候。 
	char str1[] = { 'a', 'a', 'c', 'd', 'e' };

	sizeof(str1); // 得到的是数组占据空间的大小。 

	// 如果str1 这时候当做首指针。得到的应该是指针的大小。 
	printf("%d\n", sizeof(str1));

	char *p = str1;
	printf("%d\n", sizeof(p));
}

void test2() {
	char str1[] = { 'a', 'a', 'c', 'd', 'e' };

	// char[5] * 
	//char[5] *p;

	// 使用& 对数组计算的时候，数组不会当做首指针看
	// 这时候，得到的是数组整个的地址。 
}


int main(void) {
	//test1();
	test2();

	return 0;
}