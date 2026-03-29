#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "hashmap.h"

void test1() {
	HashMap *map = hashmap_create();

	hashmap_put(map, "zhangsan", "28");
	hashmap_put(map, "lisi", "20");
	hashmap_put(map, "wangwu", "16");
	hashmap_put(map, "sihong", "17");
	hashmap_put(map, "qiyue", "18");
	hashmap_put(map, "liwang", "18");
	hashmap_put(map, "lirui", "16");

	printf("zhangsan = %s\n", hashmap_get(map, "zhangsan"));
	printf("lisi = %s\n", hashmap_get(map, "lisi"));
	printf("qiyue = %s\n", hashmap_get(map, "qiyue"));
	printf("liwang = %s\n", hashmap_get(map, "liwang"));
	printf("lirui = %s\n", hashmap_get(map, "lirui"));
	hashmap_put(map, "lirui", "17");
	printf("lirui = %s\n", hashmap_get(map, "lirui"));
}


void test2() {
	HashMap *map = hashmap_create();

	hashmap_put(map, "zhangsan", "28");
	hashmap_put(map, "lisi", "20");
	hashmap_put(map, "wangwu", "16");
	hashmap_put(map, "sihong", "17");
	hashmap_put(map, "qiyue", "18");
	hashmap_put(map, "liwang", "18");
	hashmap_put(map, "lirui", "16");
	
	printf("kongling = %s\n", hashmap_get(map, "kongling"));
	printf("kongling = %d\n", hashmap_get(map, "kongling") == NULL);
	printf("lisi = %s\n", hashmap_get(map, "lisi"));

	printf("lisi remove res = %s\n", hashmap_remove(map, "lisi"));
	printf("lisi = %s\n", hashmap_get(map, "lisi"));


}


int main(void) {
	//test1();
	test2();

	return 0;
}