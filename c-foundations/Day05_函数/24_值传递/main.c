#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void change_int_by_int(int num) {
	num = 987654;

	printf("change_int_by_int = %d\n", num);
}

void change_int_by_pointer(int *p1) {
	*p1 = 665544;
	printf("change_int_by_pointer = %d\n", *p1);
}

int main(void) {
	int a = 123;
	change_int_by_int(a);
	// a变了没有？ 
	//printf("main = %d\n", a);

	int *p123 = &a;
	change_int_by_pointer(p123);
	printf("main = %d\n", a);


	return 0;
}