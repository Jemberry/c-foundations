#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {

	//编写一个程序实现一个简单的计算器，能够处理加法、减法、乘法和除法。
	//	输入：用户输入两个数字(可以带小数)和一个操作符（ + 、 - 、 * 、 / ）。
	//	输出：显示计算的表达式及结果。
	//	注意以下几个要求：
	//	1. 代码可以直接写在main函数里，不需要提取函数。
	//	2. 输入的表达式应当符合格式要求，应当正常录入两个操作数和一个运算符，否则直接退出程序。
	//	3. 在进行除法操作时，需要保证除数不为0，若除数为0，则直接退出程序。
	//	运算结果截图如下：
	double num1, num2;
	char oper;

	// error
	//scanf("please input expression: (1 + 5): %lf %c %lf",
		//&num1, &oper, &num2);

	printf("please input expression(operator + - * /): example(1 + 5):\n");
	int ret = scanf("%lf %c %lf",&num1, &oper, &num2);
	// printf("input success count = %d\n", ret);
	// printf("input num1=%lf, operator=%c, num2=%lf\n", num1, oper, num2);

	if (oper != '+' && oper != '-' && oper != '*' && oper != '/') {
		printf("opertor not right.\n");
		// continue break return 
		return;
	}

	// 代码能往下走，说明，运算符正确。 

	if (oper == '+'){
		printf("%lf + %lf = %lf\n", num1, num2, num1 + num2);
	}
	else if (oper == '-') {
		printf("%lf - %lf = %lf\n", num1, num2, num1 - num2);
	}
	else if (oper == '*') {
		printf("%lf * %lf = %lf\n", num1, num2, num1 * num2);
	}
	else if (oper == '/') {
		printf("%lf / %lf = %lf\n", num1, num2, num1 / num2);
	}

	return 0;
}