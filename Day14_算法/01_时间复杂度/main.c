#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void test1() {
	// O(1)  O(n)  O(n^2)

	// O(n^2) 常见于循环套循环。  O(n^3)
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				// 去找具有某个特征的值。 
			}
		}
	}
	// 10w
	// O(1)  
	// O(n): 10w
	// O(n^2): 10w * 10w = 100亿
	// O(n^3) ： 10w*10w*10w = 1000w亿

	// 不要使劲套循环。 
	// 使用哈希表。 只要设计合理的key，就能避免掉这种循环。 

	// 在公司中，写好的代码，有三个注意
	// 1.代码能完成业务。 功能能实现
	// 2.可读性要求。 对于程序员自己的。 
	// 3.性能。 产品对于时间复杂度没有感知，但是运行一个程序的时间他知道。 
	// 如果时间复杂度比较差，最终他会让你修改。 


	for (int i = 0; i < 10; i++) {
		// linkedlist_get_by_idx(list, n); // 这一行的时间复杂度是O(n)

		// hashmap_get(map, "key");
	}

}

int main(void) {

	return 0;
}