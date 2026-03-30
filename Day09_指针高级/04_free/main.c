#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1() {
	// 如果光申请内存，使用完毕之后，不释放，最终会导致内存泄露。 
	// 就是程序中可用的内存越来越少。 最终会导致程序无法运行。 


	// 所以，我们在使用完毕内存之后，一定要记得及时释放。 

	int *p = malloc(24);

	if (p == NULL) {
		printf("malloc failed.\n");
		return;
	}

	for (int i = 0; i < 6; i++) {
		p[i] = i + 100;
		printf("%d\n", p[i]);
	}


	// 使用完毕之后，一定要记得释放。 
	free(p);
}


void test2() {
	// free只能传入堆区的数据，不能传栈区的。 
	// 1.不要将栈区的数据放进去。 
	// 2.只能放申请得到的堆区的首字节指针。
	// 如果传递的是后面的指针，同样报错。 

	//int arr[10] = { 10,11,12,13 };
	//free(arr);
	//int *p = arr;
	//free(p);

	int *p = malloc(24);

	//for (int i = 0; i < 6; i++) {
	//	p[i] = i + 100;
	//	printf("%d\n", p[i]);
	//}

	// p指针，动了没有。 
	//free(p);

	*p++ = 10;
	*p++ = 20;

	free(p);



}

void test3() {
	// 如果你习惯使用挪指针的写法。
	// 建议，再定义一个指针，存储旧指向，最后
	// 释放旧指向。 
	int *p = malloc(24);

	int *old_p = p;

	*p++ = 10;
	*p++ = 11;
	*p++ = 12;
	*p++ = 13;
	*p++ = 14;

	free(old_p);
}


void test4() {

	// 不能不释放； 也不能double free 
	int *p = malloc(24);

	int *old_p = p;

	p[0] = 10;
	p[1] = 11;
	p[2] = 12;
	p[3] = 13;

	free(p);
	free(old_p);
}



int main(void) {

	//test1();
	//test2();
	//test3();
	test4();

	return 0;
}