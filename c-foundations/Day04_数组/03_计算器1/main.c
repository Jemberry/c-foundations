#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	while (1) {
		double num1, num2;
		char oper;

		printf("please input expression(operator + - * /): example(1 + 5):\n");

		int ret = scanf("%lf %c %lf", &num1, &oper, &num2);
		while (getchar() != '\n');

		if (ret != 3) {
			// Àµ√˜ ‰»Î ß∞‹°£ 
			printf("input not right.\n");
			continue;
		}

		if (oper == '+') {
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

		printf("are you continue?(y/Y)\n");

		char flag = 'n';

		scanf(" %c", &flag);

		while (getchar() != '\n')
			;

		if (flag != 'y' && flag != 'Y') {
			break;
		}
	}

	

	return 0;
}