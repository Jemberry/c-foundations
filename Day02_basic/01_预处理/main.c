#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10

// 宏定义函数，要注意。 它只做文本替换。 没有什么优先级。 
// 所以在定义的时候，要加括号。 
//#define SQRT_DIFF(x,y) (x*x - y*y)
#define SQRT_DIFF(x,y) ((x)*(x) - (y)*(y))

int main(void) {

	// 这是一个注释。

	printf("hello world.\n");
	printf("maxsize = %d\n", MAX_SIZE);
	printf("sqrt_diff = %d\n", SQRT_DIFF(5, 4));
	printf("sqrt_diff = %d\n", SQRT_DIFF(2+3, 4));

	return 0;
}