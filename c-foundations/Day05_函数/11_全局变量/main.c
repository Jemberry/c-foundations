#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 全局变量： 就是定义在函数外的变量。 
// 存储位置： 存储在数据段中。 生命周期：就是程序启动就活着，程序结束才挂掉。 
// 作用域： 在定义它的位置之后就可以使用到它。  或者其他文件中能用到它。 
int global_num1 = 10086;

int main(void) {

	printf("%d\n", global_num1);
	printf("%d\n", global_num2);

	return 0;
}

int global_num2 = 100000;