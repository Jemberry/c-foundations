#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1() {

	void *p = malloc(10 * sizeof(int));

	// 这个就代表从堆区中申请了 40个字节。 
	// 返回值表明，申请得到的地址是什么。 
	// 这块空间是连续的，所以它只告诉了你首地址。 

	// 返回值，有两种情况
	// 1. 得到一个地址（非NULL）. 表明申请成功
	// 2.得到一个NULL. 表明申请失败。 
}

void test2() {
	// 动态内存申请的标准步骤

	// 1.申请空间
	void *p = malloc(10 * sizeof(int));

	// 2.判断是否申请成功
	if (p == NULL) {
		printf("malloc failed.\n");
		return;
	}

	// 3.使用
	// 直接当数组使用。 
	// p[0] = 0; // 不能直接使用。 

	int *p_int = (int *)p;
	for (int i = 0; i < 10; i++) {
		p_int[i] = i;
		//p_int[0] = i;
	}

	for (int i = 0; i < 10; i++) {
		printf("--------%d\n", p_int[i]);
	}

	// 4.释放。 
	free(p_int);
}

void test3() {
	// 现在，要申请 20个 char  怎么写？
	//void *p = malloc(20 * sizeof(char));
	char *p = malloc(20 * sizeof(char));

	if (p == NULL) {
		printf("malloc failed.\n");
		return;
	}

	for (int i = 0; i < 20; i++) {
		p[i] = 'a' + i;
	}

	for (int i = 0; i < 20; i++) {
		printf("%c-----\n", p[i]);
	}
	// 内存，连续的。 直接看一下内存。 
	// char *p = malloc(20 * sizeof(char));
	// 在内存里面，做了哪些事情。 
}


void test4() {
	// malloc 怎样知道，你申请的是int 还是 char   还是double的？》

	//int *p = malloc(40);
	//float *p = malloc(40);
	float *p = malloc(10 * sizeof(int));

	// malloc怎么知道你申请的是int的？
	// malloc 不知道，也不关心。 程序员需要知道和关心。 
	// 程序员通过指针告诉它，怎样对待这块内存的。 

	if (p == NULL) {
		printf("malloc failed.\n");
		return;
	}

	for (int i = 0; i < 10; i++) {
		p[i] = i + 10;
	}

	for (int i = 0; i < 10; i++) {
		printf("=======%f\n", p[i]);
	}
}

int main(void) {

	//test2();
	//test3();
	test4();

	return 0;
}