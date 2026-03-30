#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

typedef int DataType;

void test1() {
	// 类型别名，就是可以为系统中的一些原有类型，取别的名字

	DataType data = 10;
	printf("%d\n", data);

	// Node 
}

void test2() {
	// 如果在系统中，大量使用的某一个变量，是int
	// 大多数情况下，是4个字节。 

	// 过了一段时间，我们发现4个字节不够装。 


	// 可以提升代码的跨平台移植性。 
	// 大多数情况下，int 是4个字节。 

}


void test3() {
	// 在Linux系统中，大量使用了类型别名。 

	// sizeof()
	// 系统提供的类型别名，基本有一个特征。 以  _t 
	// 见到 _t 一定要知道它是类型别名。 

	// size_t: 是一个和系统位数相关的无符号整数
	int8_t;
	int16_t;
	int32_t;
	uint32_t;

}

int main(void) {

	test1();

	return 0;
}