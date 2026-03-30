#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linkedlist.h"


void test1() {
	LinkedList *list = linkedlist_create();

	linkedlist_insert_before_head(list, 9);
	linkedlist_insert_before_head(list, 8);
	linkedlist_insert_before_head(list, 10);
	linkedlist_insert_before_head(list, 5);
	linkedlist_insert_before_head(list, 3);
	linkedlist_insert_before_head(list, 1);

	//  1 3   5  10 8 9
	linkedlist_print(list);

	printf("size = %d\n", list->size);
}


void test2() {
	LinkedList *list = linkedlist_create();

	linkedlist_insert_after_tail(list, 3);
	linkedlist_insert_after_tail(list, 8);
	linkedlist_insert_after_tail(list, 7);
	linkedlist_insert_after_tail(list, 5);
	linkedlist_insert_after_tail(list, 4);
	linkedlist_insert_after_tail(list, 6);
	linkedlist_insert_after_tail(list, 110);

	//  1 3   5  10 8 9
	linkedlist_print(list);

	printf("size = %d\n", list->size);
}

void test3() {
	LinkedList *list = linkedlist_create();

	linkedlist_insert_after_tail(list, 3);
	linkedlist_insert_after_tail(list, 8);
	linkedlist_insert_after_tail(list, 7);
	linkedlist_insert_after_tail(list, 5);
	linkedlist_insert_after_tail(list, 4);
	linkedlist_insert_after_tail(list, 6);
	linkedlist_insert_after_tail(list, 110);
	//  0  1   2  3  4 5 
	//  3  666 8  7  5  4  6   110

	linkedlist_insert_by_idx(list, 1, 666);
	linkedlist_print(list);
	linkedlist_insert_by_idx(list, 0, 888);
	linkedlist_print(list);
	linkedlist_insert_by_idx(list, list->size, 777);

	linkedlist_print(list);
}

void test4() {
	// 一定要掌握的是： 如果我将前驱的指针给你。 你能否将这个数据插入。 
}

void test5() {
	LinkedList *list = linkedlist_create();

	linkedlist_insert_after_tail(list, 3);
	linkedlist_insert_after_tail(list, 8);
	linkedlist_insert_after_tail(list, 7);
	linkedlist_insert_after_tail(list, 5);
	linkedlist_insert_after_tail(list, 4);
	linkedlist_insert_after_tail(list, 6);
	linkedlist_insert_after_tail(list, 110);

	//  3   8   7   5   4   6   110
	linkedlist_delete_by_value(list, 220);
	linkedlist_print(list);

	linkedlist_delete_by_value(list, 3);
	linkedlist_print(list);

	// 8--->7--->5--->4--->6--->110
	linkedlist_delete_by_value(list,4);
	//8--->7--->5--->6--->110

	linkedlist_delete_by_value(list, 5);
	linkedlist_delete_by_value(list, 6);
	linkedlist_delete_by_value(list, 7);
	linkedlist_print(list);

	linkedlist_delete_by_value(list, 8);
	linkedlist_delete_by_value(list, 110);
	linkedlist_print(list);

	linkedlist_insert_after_tail(list, 1);
	linkedlist_insert_after_tail(list, 2);
	linkedlist_insert_after_tail(list, 3);
	linkedlist_print(list);
}

int main(void) {
	//test1();
	//test2();
	//test3();
	test5();

	return 0;
}