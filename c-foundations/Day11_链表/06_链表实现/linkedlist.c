#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList *linkedlist_create() {
	// 怎样创建一个链表出来、。 
	LinkedList *list = malloc(sizeof(LinkedList));
	// if list ！= NULL

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

void linkedlist_destory(LinkedList *list) {
	Node *tmp = list->head;

	while (tmp != NULL){
		Node *next = tmp->next;
		// 说明 tmp不为空，说明tmp 指向一个有东西的地方。 
		free(tmp);
		tmp = next;
	}

	free(list);
}
void linkedlist_print(LinkedList *list) {
	// 打印数据。  如何在不借助 size的情况下，也可以打印。 
	Node *tmp = list->head;

	if (tmp == NULL) {
		// 说明里面一个数据都没有。 
		printf("linkedlist empty.\n");
		return;
	}

	// 1--->2--->6--->8
	while (tmp!= NULL){
		printf("%d", tmp->data);
		tmp = tmp->next;
		if (tmp != NULL) {
			printf("--->");
		}
	}
	printf("\n");
}

// 增删改查
void linkedlist_insert_before_head(LinkedList *list, DataType data) {
	// 头插。 
	// 如果之前没有数据，维护比较简单。 
	Node *new_node = calloc(1, sizeof(Node));

	// if 
	new_node->data = data;

	if (list->head == NULL) {
		// 链表中没有数据。 head tail都指向这个new_node
		list->head = new_node;
		list->tail = new_node;
		list->size++;
		return;
	}

	// 代码凡是走到这里。说明。 

	new_node->next = list->head;
	//new_node->next = list->head->next; //error
	list->head = new_node;
	list->size++;
	// 如果之前有数据，维护步骤会多一些。 
}

void linkedlist_insert_after_tail(LinkedList *list, DataType data) {
	// 尾插。 
	Node *new_node = calloc(1, sizeof(Node));
	// if new_node != NULL

	new_node->data = data;

	if (list->head == NULL) {
		list->head = new_node;
		list->tail = new_node;
		list->size++;
		return;
	}

	// 往下走，说明之前肯定有数据。 

	list->tail->next = new_node;
	list->tail = new_node;
	list->size++;

}


void linkedlist_insert_by_idx(LinkedList *list, int idx, DataType data) {
	// 按照索引插。  

	// [0, size]范围有效。 其他范围 

	if (idx < 0 || idx > list->size) {
		printf("idx illegal.\n");
		return;
	}

	if (idx == 0) {
		// 说明就是头插。 
		linkedlist_insert_before_head(list, data);
		return;
	}

	if (idx == list->size) {
		linkedlist_insert_after_tail(list, data);
		return;
	}

	// 代码走到这来。说明，不是头插，也不是尾插。 
	// 怎么插？ 在链表中，要操作某一个结点，需要找到这个结点的前驱结点。 

	Node *pre_node = NULL;
	Node *cur_node = list->head;

	for (int i = 0; i < idx; i++) {
		pre_node = cur_node;
		cur_node = cur_node->next;
	}
	// 带入试一下。 

	// 结束之后。pre_node 里面存的就是前驱。 

	Node *new_node = calloc(1, sizeof(Node));
	new_node->data = data;

	new_node->next = pre_node->next;
	pre_node->next = new_node;
	list->size++;

	// 中间插入。 
}


void linkedlist_delete_by_value(LinkedList *list, DataType data) {
	// 前后指针。 

	// 是否有这个数据。  如果有这个数据，需要找到它的前驱指针。 

	Node *pre_node = NULL;
	Node *cur_node = list->head;
	while (cur_node != NULL){
		if (cur_node->data == data) {
			// 说明找到了。 
			break;
		}
		// 说明当前的数据，不是要删除的数据。 
		pre_node = cur_node;
		cur_node = cur_node->next;
	}

	// 如果没找到。 因为是删除函数。 所以，不用做任何操作。 
	if (cur_node == NULL) {
		// 说明没找到。 不处理. 
		printf("data not found = %d\n", data);
		return;
	}

	// 走到这，说明找到了。 
	// 第一个， 中间，最后。 

	if (pre_node == NULL) {
		// 说明要删除的数据是第一个。 
		list->head = cur_node->next;
		list->size--;

		// 判断是否只有一个数据。 
		// list->size == 0;  list->head==NULL
		if (list->head == NULL) {
			list->tail = NULL;
		}

		free(cur_node);
		return;
	}

	// 代码，往下走，说明不是第一个。 
	// 中间的，或者最后的。 

	pre_node->next = cur_node->next;
	free(cur_node);

	list->size--;

	if (pre_node->next == NULL) {
		// 说明要删除的数据是最后一个
		list->tail = pre_node;
	}

}