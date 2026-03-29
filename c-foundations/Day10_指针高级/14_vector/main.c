#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {

	// Vector 是C++中提供的一种东西。 
	// 专门用于存放数据。 

	// 我们可以认为这是一个数组。 
	// 和我们平常的数组的主要区别，是长度可变。 

	// 基本思路： 要用堆空间。 刚开始申请一点空间，如果装到装不下的时候，继续
	// 申请空间。 

	// Vector要存什么信息
	// 1. 元素能放多少个。   10
	// 2. 数据。 
	// 3. 现在装了多少数据。 

	int arr[10];
	int *p = malloc(40);

	return 0;
}