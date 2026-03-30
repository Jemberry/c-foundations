#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void test1() {
	// realloc用于，将已经得到的堆空间，弄大，或者缩小。 
	// realloc 会将数据复制过去。 
	// 32    -->   60   ===> 28
}

void test2() {
	char *p = malloc(40);
	// if

	// ....

	p = realloc(p, 60);
	// 这样有问题。 申请内存，有成功，还是失败。 

	// 失败的时候，并不会直接free掉空间。 会返回NULL
}


void test3() {
	char *p = malloc(40);

	// if

	// ....
	char *new_p = realloc(p, 60);

	
	if (new_p == NULL) {
		// 说明失败了。 
		printf("realloc faild.\n");
		free(p);
		return;
	}
	p = new_p;
}

int main(void) {

	return 0;
}