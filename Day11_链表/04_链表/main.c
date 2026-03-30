#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 链表，由结点构成。 结点里面有两部分，一部分是数据，一部分是指针。 
typedef struct node_s {
	int data;
	// next指针，用于存储下一个结点的地址。 
	struct node_s *next;
}Node;

typedef struct node_s1 {
	int data;
	//Node1 *next; // 在结构体内部，一定不能用自己的别名。 
}Node1;


int main(void) {

	//Node n1;
	//Node.data

	//Node1 *next;

	//Node n1;
	//n1.data;

	Node1 n2;

	return 0;
}