#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test1() {
	// 随机数怎样生成？
	// 1.引入头文件。  stdlib.h   time.h
	// 2.设置种子值。 srand();
	// 3.使用rand()得到随机数。 
	srand(3);

	int random_value1 = rand();
	int random_value2 = rand();
	int random_value3 = rand();

	printf("value1 = %d\n", random_value1);
	printf("value2 = %d\n", random_value2);
	printf("value3 = %d\n", random_value3);
	// 1.rand得到的其实是一个伪随机数。 
	// 随机数和 srand()种子值相关。 


}


void test2() {
	// 设置种子值1，然后使用rand() 会得到一个固定的序列
	// 48   7196  9294  6636  6535
	srand(3);

	for (int i = 0; i < 5; i++) {
		printf("round1======%d\n", rand());
	}

	srand(3);
	for (int i = 0; i < 5; i++) {
		printf("round2======%d\n", rand());
	}
	// 设置种子值1， 然后使用rand() 会得到一个固定的序列
}

void test3() {
	// 时间是永不重复的。 

	// 我们可以将时间塞到 srand中当做种子值。 
	// 时间戳： 从当前时间距离格林威治时间的秒数的差值，
	// 可以用来唯一标识这个时间。 

	// 1970-01-01 00:00:00

	printf("%d\n", time(NULL));
}

void test4() {
	// 时间戳是一个公共的概念，其他的语言，数据库中都有这个概念。 
	// 大家在使用时间戳的时候，要注意一下，单位是秒还是毫秒。 
}

void test5() {
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		printf("round1======%d\n", rand());
	}

	// srand(3);
	// rand();
	// srand(3);
	// rand();
}

void test6() {
	//srand(time(NULL));

	for (int i = 0; i < 100000; i++) {
		srand(time(NULL));
		printf("round1======%d\n", rand());
	}

	// srand(3);
	// rand();
	// srand(3);
	// rand();
}


void test7() {
	// rand() 生成的随机数， 范围是 [0, RAND_MAX]
	//RAND_MAX;
}


int main(void) {


	//test1();
	//test2();
	//test3();
	//test5();
	test6();

	return 0;
}