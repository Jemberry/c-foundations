#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 关于录入字符，单独提一下。 

	char ch = 'a';

	// 假设，现在要录入一个字符。 
	//scanf("%c", &ch);
	scanf(" %c", &ch);

	// %c 会匹配字符，。 空格也算字符。 
	// 所以建议，在 %c的前面加上 空格
}

void test2() {
	// 如果在输入多种类型的时候，stdin中可能会残存 \n  空格。 

	int num1 = 10;
	char ch = 'z';

	scanf("%d", &num1);
	//scanf("%c", &ch);
	scanf(" %c", &ch);

}


int main(void) {

	//test1();
	test2();


	return 0;
}