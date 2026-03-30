#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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

int main(void) {

	// 给定一个数组。 怎样将数组分区。 左边是比这个数据小，右边比它大。 
	int arr[] = { 16,22,28,1,7,5,3,2,4 ,50 };
	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	// 假设，想将 数组按照 16来分区。 左边比16小，右边比16大。 
	int pivot_index = 0; // 枢纽值的选择很关键。 
	//int pivot_index = (rand() % sub_len) + left;
	// SWAP(arr, left, pivot_index);

	int pivot_value = arr[pivot_index];

	int cur_l = 0;
	int cur_r = ARR_LEN(arr) - 1;

	while (cur_l < cur_r){
		// 从右往左找。 找比枢纽值小的。 
		while (cur_l < cur_r && arr[cur_r] > pivot_value){
			cur_r--;
		}
		if (cur_l < cur_r) {
			arr[cur_l] = arr[cur_r];
		}

		while (cur_l < cur_r && arr[cur_l] <= pivot_value) {
			cur_l++;
		}
		if (cur_l < cur_r) {
			arr[cur_r] = arr[cur_l];
		}
	}

	arr[cur_l] = pivot_value;

	print_arr(arr, ARR_LEN(arr));

	return 0;
}