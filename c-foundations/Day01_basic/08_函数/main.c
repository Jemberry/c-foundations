#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 函数返回值类型 函数名(形参列表){
//  函数体
// 
//  return 返回值。 
// }

int add(int num1, int num2) {
	printf("add------%d + %d\n", num1, num2);
	return num1 + num2;
}

int main(void) {

	// 函数写好之后，只是定义了一个架子。但是不调用，是不会直接运行的。 
	int num333 = 789;
	int num444 = 100;
	//add(int num333, int num444);
	int res = add(num333, num444);

	// 写一个函数，没有入参，没有返回值的
	// 写一个函数，有两个double入参，没有返回值。 
	// 写一个函数，有三个double入参，返回int。  
	// 写一个函数，有三个int入参，返回double。  
	// 敲的代码痕迹要存一下。 不要将文件删了。 

	printf("%d\n", res);

	return 0;
}