#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 假设，进公司，我们公司是做网盘项目的。 

	// 百度网盘。 

	// 假设，百度网盘，下载的时候限速。 
	// 根据用户的等级进行限速。 

	// 0   1   2   3   4  5  
	// vip_level 

	// 现在，假设在很多下载的函数内部，都需要进行限速。 
	// 100处，都需要写这个限速的逻辑。 

	int limit_speed = 0;
	int vip_level = 1;

	if (vip_level == 0) {
		limit_speed = 50;
	}
	else if (vip_level == 1) {
		limit_speed = 200;
	}
	else if (vip_level == 2) {
		limit_speed = 800;
	}
	else if (vip_level == 3) {
		limit_speed = 1600;
	}
	else if (vip_level == 4) {
		limit_speed = 3200;
	}

}

void test2() {
	// main里面写所有的代码
	// 但是要养成习惯： 尽量抽函数， 因为抽了函数，逻辑会清晰一些
	// 后期的改动也会容易一些。 
}


int main(void) {

	return 0;
}