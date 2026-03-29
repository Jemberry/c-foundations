#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void test1() {
	// fwrite ：写。 是以二进制模式写。 
	int arr[] = { 10,11,12,13,14,15 };
	// 00 00 00 0a

	FILE *fp = fopen("1.dat", "wb");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	size_t ret = fwrite(arr, sizeof(int), 6, fp);

	printf("ret = %d\n", ret);

	fclose(fp);
}

void test2() {
	FILE *fp = fopen("1.dat", "rb");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	// 13个  int 
	int arr[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

	size_t ret = fread(arr, sizeof(int), 13, fp);

	printf("ret = %d\n", ret);

	fclose(fp);
}

typedef struct student {
	int id;
	char name[25];
	int chinese;
	int math;
}Student;

void test3() {
	// 如果有一个结构体，能否直接用 fwrite 将其写出。 
	// 序列化。反序列化。 
	// 编码 解码。 
}

int main(void) {
	//test1();
	test2();
	return 0;
}