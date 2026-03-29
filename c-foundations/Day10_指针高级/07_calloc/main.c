#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1() {
	// calloc 从堆上申请内存，它和malloc的区别，就是它会将内存清零。
	
	//int *p = calloc(8, sizeof(int));
	int *p = calloc(9, sizeof(int));
	// 最终申请  8 * sizeof(int)

	// if
	for (int i = 0; i < 8; i++) {
		printf("===========%d\n", p[i]);
	}

	// 为什么光传入了 p。 不用告诉它大小。
	// 因为系统在这个地址的前面几个字节，存储了它这个内存单元实际占据的大小。
	// 系统会存，但是大家不要去取，容易翻车。 
	free(p);
}

int main(void) {

	test1();

	return 0;
}