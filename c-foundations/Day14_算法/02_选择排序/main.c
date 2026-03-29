#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))
#define SWAP(arr, i, j) { \
int tmp=arr[i]; \
arr[i]=arr[j]; \
arr[j]=tmp;\
}

void print_arr(int arr[], int len) {
	// [1,2,3,4]
	for (int i = 0; i < len; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void select_sort(int arr[], int len) {
	// 选择排序。 
	for (int i = 0; i < len; i++) {
		// i===> 0---len-1
		int min_index = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		SWAP(arr, i, min_index);
		print_arr(arr, len);
	}

	// n-1 + n-2 + n-3 +... +1 

	// 时间复杂度。 O(n^2)
	// 空间复杂度  O(1)
	// 稳定性 : 不稳定。
}


int main(void) {
	// 选择排序： 就是将数据选到前面来。 
	// 每一轮，将剩下的数据的最小值/最大值 选到名义上的最前面。 
	// 这样结束之后就是有序的。 

	// 10 8 6 3 1 40 35 22 31 
	// 1 3 6 8 10 22 35 40 31 

	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };

	select_sort(arr, ARR_LEN(arr));

	print_arr(arr, ARR_LEN(arr));

	return 0;
}