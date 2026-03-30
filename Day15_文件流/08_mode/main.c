#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// r模式的问题。 r表示读
	// w 表示写
	// a 表示追加。 
}
void test2() {
	// r. 读，只能读。
	// 如果是以读模式打开，文件存在打开成功； 文件不存在打开失败。 
	FILE *fp = fopen("1.txt", "r");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}
}

void test3() {
	// w 写。 如果文件存在，打开成功且文件内容消失，内容清空
	// 如果文件不存在，会新建文件。

	//FILE *fp = fopen("2.txt", "w");
	FILE *fp = fopen("2222.txt", "w");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	printf("fopen success.\n");


	fclose(fp);
}

void test4() {
	FILE *fp = fopen("3333.txt", "a");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	printf("fopen success.\n");

	fputc('z', fp);
	fputc('x', fp);
	fputc('y', fp);

	fclose(fp);
}


void test5() {
	// 不建议使用混合模式。  r+ w+ a+
	// 因为极其容易出问题，且很让问困惑。 

	FILE *fp = fopen("444.txt", "r+");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	printf("ch1 = %c\n", fgetc(fp));
	printf("ch2 = %c\n", fgetc(fp));
	printf("ch3 = %c\n", fgetc(fp));

	fputc('1', fp);
	fputc('2', fp);
	fputc('3', fp);
	fputc('4', fp);
	fputc('5', fp);
	fputc('6', fp);
	fputc('7', fp);

	// 模式尽量只使用读，或者写，或者追加。 
	// 不要开读写。 一会读一会写，很容易翻车。 
	fclose(fp);


}


int main(void) {

	//test3();
	//test4();
	test5();

	return 0;
}