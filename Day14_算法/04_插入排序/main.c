#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))
#define SWAP(arr, i, j) { \
int tmp=arr[i]; \
arr[i]=arr[j]; \
arr[j]=tmp;\
}

void print_arr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void insert_sort(int arr[], int len) {
	// 插入排序，就是刚开始认为第一个数据有序。 然后将后面的数据，挨个往里面插入。 
	// 数据插入结束，就有序了。 

	for (int i = 1; i < len; i++) {
		// 说明从 index = 1
		int need_insert_value = arr[i];

		int need_check_index = i - 1;

		while (need_check_index >= 0 && need_insert_value < arr[need_check_index]){
			// 说明什么。 
			arr[need_check_index + 1] = arr[need_check_index];
			need_check_index--;
		}

		arr[need_check_index + 1] = need_insert_value;

		print_arr(arr, len);
	}
	// 时间复杂度：O(n^2)
	// 空间复杂度： O(1)
	// 稳定性： 稳定
}

void test2() {
	// 插入排序有一种极端情况： 完全逆序的。 
}


int main(void) {

	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	print_arr(arr, ARR_LEN(arr));

	insert_sort(arr, ARR_LEN(arr));

	print_arr(arr, ARR_LEN(arr));

	return 0;
}