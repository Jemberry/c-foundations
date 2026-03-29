#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 数组因为是连续内存空间，每一个数据类型一致。 
	// 现在造成了它具有一个非常优秀的特点： 随机访问。 

	// 什么是随机访问。 
	// 想访问第n个数据，可以直接访问到第n个数据，不需要经过前面 的 0 1 2 3 4....
	// 因为数据的内存是连续的，并且里面存储的类型是一致的。 所以，我们只需要根据
	// 首地址 + 偏移量，就可以直接算出第n个数据的地址，直接去这个地址取数据即可。 

	int arr[8] = { 5,6,7,8,9,10,11,12 };

	// 计算index=4的数据。 
	// 0x012FF5E8 + 4 * 4
	// 0x012FF5F8
	arr[4]

}

int main(void) {

	int score1 = 90;
	int score2 = 90;
	int score3 = 90;
	int score4 = 90;
	int score5 = 90;
	int score6 = 90;
	int score7 = 90;
	int score8 = 90;
	int score9 = 90;
	int score10 = 90;
	int score11 = 90;

	// 数组的一个变量，可以存储多个数据。 
	int score_list[10] = { 90,80,70,75,74,73,98,88 };
	// 4    4     (40)

	test1();

	return 0;
}