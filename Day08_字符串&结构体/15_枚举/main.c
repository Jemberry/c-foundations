#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SVIP_0 0
#define SVIP_1 1
#define SVIP_2 2
#define SVIP_3 3
#define SVIP_4 4


//在编程中，我们可能会碰到一个场景，需要对一系列的状态 / 离散的数值进行逻辑处理。
void test1() {
	// 百度网盘。 

	// 会员等级。 
	// 在代码中，这个东西怎么表示。 
	// 1.使用一个整型来表示这个事情。 
	// int vip_levl = 0 1 2 3 4 5 6 7 8 9 10 11;
	// 可以，但是需要过度依赖于程序员的记忆力。 

	// 2.使用宏定义来做这个事情。
	// 可以完成， 它可以提升一些代码的可读性。 但是问题在
	// 这个东西多了，不好搞。 

	// 3.可以使用枚举来将这些定义放在一个结构中。 

}



int main(void) {

	return 0;
}