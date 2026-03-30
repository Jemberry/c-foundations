#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 二级指针，就是指针的指针。 也就是，存储指针地址的
	int num = 10;
	int num2 = 9990;

	int *p1 = &num;
	// *p1 = 10086;

	// 如果想改变，p1的指向。 
	//p1 = &num2;

	int **pp1 = &p1;
	*pp1 = &num2;

	printf("%d\n", *p1);
}

void change_int_by_int(int num) {
	// 函数内部，去修改外部调用者的  int值。
	// 以达到传递信息的目的，能否实现。 
	num = 10086;
}

void change_int_by_pointer(int *p1) {
	*p1 = 9998887;
}

int global_num = 654654654;
void change_pointer_by_pointer(int *p1) {
	p1 = &global_num;
	printf("in change_pointer_by_pointer num = %d\n", *p1);
}

void change_pointer_by_pointerpointer(int **pp) {
	*pp = &global_num;
}

void test3() {
	//int a = 10;
	//change_int_by_int(a);
	//printf("change after=====%d\n", a);

	//int a = 10;
	//int *p1 = &a;
	//change_int_by_pointer(p1);
	//printf("change after=====%d\n", a);

	int a = 10;
	int *p1 = &a;
	//change_pointer_by_pointer(p1);
	//printf("change after pointer=====%d\n", *p1);

	int **pp1 = &p1;
	change_pointer_by_pointerpointer(pp1);
	printf("change after pointerpointer=====%d\n", *p1);
}


void test2() {
	// 二级指针，是存储一级指针的地址的指针。 
	// 它有什么用。 

}


int main(void) {

	//test1();
	test3();

	return 0;
}