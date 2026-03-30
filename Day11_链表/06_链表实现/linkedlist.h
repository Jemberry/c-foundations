#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef int DataType;
typedef struct node {
	DataType data;
	struct node *next;
}Node;

typedef struct {
	Node *head; // 头指针
	Node *tail; // 尾指针
	int size; // 里面的结点数量。 
}LinkedList;

// 创建链表。 销毁链表。打印链表
LinkedList *linkedlist_create();
void linkedlist_destory(LinkedList *list);
void linkedlist_print(LinkedList *list);

// 增删改查
void linkedlist_insert_before_head(LinkedList *list, DataType data);
void linkedlist_insert_after_tail(LinkedList *list, DataType data);
void linkedlist_insert_by_idx(LinkedList *list,int idx, DataType data);

// 删除数据。 按照下标删除。 按照值删除。 
// 1.按照下标删除。
// 2.删除第一个出现的该值。 
void linkedlist_delete_by_value(LinkedList *list, DataType data);



#endif // !LINKEDLIST_H
