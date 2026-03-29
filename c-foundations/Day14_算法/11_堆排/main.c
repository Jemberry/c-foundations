#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

void heapify(int arr[], int root_idx, int tree_len) {
	// 基本思路： 拿 root_idx 和 左孩子 右孩子比，将大于的换上来。 
	// 再重复这个操作。 
	while (1){
		int max_idx = root_idx;
		int left_idx = root_idx * 2 + 1;
		int right_idx = root_idx * 2 + 2;

		if (left_idx < tree_len && arr[left_idx] > arr[max_idx]) {
			max_idx = left_idx;
		}
		if (right_idx < tree_len && arr[right_idx] > arr[max_idx]) {
			max_idx = right_idx;
		}

		// 这一轮循环结束。 
		if (max_idx != root_idx) {
			SWAP(arr, max_idx, root_idx);
			root_idx = max_idx;
		}
		else {
			break;
		}

		
	}
}

void heap_sort(int arr[], int len) {
	// 第一次建堆
	// 当前下标是 i。 左孩子 2i+1  右孩子 2i+2
	for (int i = len - 1; i >= 0; i--) {
		heapify(arr, i, len);
	}

	int tree_len = len;
	// 将堆顶数据不断 换到最后。 再维护这个树。 
	for (int i = 0; i < len; i++) {
		SWAP(arr, 0, tree_len - 1);
		tree_len--;
		// 0
		heapify(arr, 0, tree_len);
	}
}

int main(void) {
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	print_arr(arr, ARR_LEN(arr));
	heap_sort(arr, ARR_LEN(arr));
	print_arr(arr, ARR_LEN(arr));

	return 0;
}