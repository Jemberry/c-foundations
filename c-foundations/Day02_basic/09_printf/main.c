#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	printf("hello world.\n");

	for (int i = 0; i < 10; i++) {
		printf("hello ------ %d\n", i);
	}


	// printf是有一个缓冲区的， 缓冲区在内存上
	// 其实是为了平衡 速度 和成本之间的关系。 
	//stdout;

	// 缓冲区有几种分类：缓冲区的大小基本不会特别大，4K左右
	// 1.满缓冲区。 如果往缓冲区中写数据，缓冲区满了，会刷新到目的地。 
	// 文件，后续我们会在代码中读写文件，这就是一个满缓冲区。 
	// 2.行缓冲区。 如果往缓冲区写数据，见到了换行符，会刷新到目的地。
	// 标准输出，就是一个行缓冲区，见到换行符，就往屏幕输出。 
	// 3.无缓冲区。 往缓冲区写数据，直接输出。 


	// 对于我们来说，目前的意义
	// 如果printf的时候，加换行符，不影响逻辑， 这时候，建议统一加上 \n
	printf("hello world.\n");

	int ret = printf("hello\n");
	printf("ret = %d\n", ret);      // 正常输出了6个字符，所以返回值是6

	int ret2 = printf("");
	printf("ret2 = %d\n", ret2);        // 正常输出了0个字符，所以返回值是0

	return 0;
}