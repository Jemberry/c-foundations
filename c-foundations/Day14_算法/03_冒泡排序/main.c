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

void bubble_sort(int arr[], int len) {
	// 冒泡排序的思路： 就是每一轮比较相邻的两个数据。 如果前面的数据小，后面的数据大
	// 说明对； 否则，说明不对。 将这两个数据调位置。 
	// 继续处理下一轮。 
	// 1 + 2 + 3 ++++ n-1
	for (int j = 0; j < len; j++) {
		bool swap_flag = false;
		for (int i = 0; i < len - 1 - j; i++) {
			if (arr[i] > arr[i + 1]) {
				SWAP(arr, i, i + 1);
				swap_flag = true;
			}
		}

		if (swap_flag == false) {
			// 说明没有进入if 。说明数据已经有序。 
			break;
		}

		print_arr(arr, len);
	}

	// 时间复杂度： O(n^2)
	// 空间复杂度：O(1)
	// 稳定性： 稳定的。 
}


int main(void) {

	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };

	bubble_sort(arr, ARR_LEN(arr));

	print_arr(arr, ARR_LEN(arr));

	return 0;
}