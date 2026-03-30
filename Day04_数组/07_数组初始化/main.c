#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	//数组初始化的方式
	//1.完整初始化
	//2.部分初始化
	//3.全部初始化为0

	int arr[8] = { 1,2,3,4,5,6,7,8 };

	char str1[5] = { 'a', 'b', 'c', 'd', 'e' };

	int arr2[] = { 10,80,90,60,50 };
}

void test2() {
	int arr[10] = { 0 };

	int arr2[8];
}

void test3() {
	//int arr[5] = { 1,2,3,4,5,6 };

	//int arr[3] = {};


	// 在C语言中，不允许数组长度是0. 
	//char str1[0];
	//char str2[-5];
	//char str3[] = {};
}

void test4() {
	// 数组元素的读和修改。 
	int arr[10] = { 10,20,30,40,50,60,70,80,90,100 };

	arr[0];
	arr[1];
	arr[9];
	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
	printf("%d\n", arr[9]);

	arr[0] = 777;
	arr[1] = 888;

	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);


}

int main(void) {

	test4();

	return 0;
}