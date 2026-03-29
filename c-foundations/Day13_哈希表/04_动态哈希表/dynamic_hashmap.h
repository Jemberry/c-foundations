#ifndef HASHMAP_H
#define HASHMAP_H

// 头文件中，有哪些内容。 
// 结构体、类型别名、函数声明、宏定义。 
// ----会存储对应的。 哈希表的头文件中会存储哈希表相关的内容

// 哈希表中，存储的数据是键值对；
// 哈希表的基本结构，是数组+链表。 
// 哈希表中无法存储重复的key。 

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define HASHMAP_INIT_CAPACITY 10
#define LOAD_FACTOR_THRESHOLD 0.75f
typedef char *KeyType;
typedef char *ValueType;

typedef struct node_s {
	KeyType key;
	ValueType value;
	struct node_s *next;
}KeyValueNode;

// 数组 + 链表
typedef struct {
	// int * --> 指向。 int数组。 int, int ,int ,int ,int 
	// int ** -->   int *, int *, int *, int *,int *, int *
	// KeyValueNode ** ---> KeyValueNode *, KeyValueNode *,KeyValueNode *

	// KeyValueNode *table[HASHMAP_INIT_CAPACITY];
	// 空间需要从堆上申请。 table，只是
	KeyValueNode **table;

	int length;
	int size; // 哈希表中存储的元素个数。 键值对算一个数据。 
	uint32_t seed;
}HashMap;

// 函数声明。 
// 基本操作： 哈希表的创建，哈希表的销毁，哈希表的打印
// 增 删 改 查：
// 增和改的逻辑是在一起的。 其实对于使用会友好一点。 
// 增改写在一起。 zhangsan  zhangsan zhangsan 
// 先判断是否存在这个键；
// if(hash_contains(map, "key")){
//     hashmap_update(....);
// }else{
//    hashmap_add(....);
// }

HashMap *hashmap_create();
void hashmap_destory(HashMap *map);
void hashmap_print(HashMap *map);


// 返回值，返回旧值； 如果键不存在，返回NULL; 如果键存在，返回旧值。
ValueType hashmap_put(HashMap *map, KeyType key, ValueType value);
ValueType hashmap_remove(HashMap *map, KeyType key);
// 如果不存在，返回NULL； 存在返回值。
ValueType hashmap_get(HashMap *map, KeyType key);

bool hashmap_contains(HashMap *map, KeyType key);

#endif // !HASHMAP_H
