#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1() {
	int arr1[] = { 1,3,5,6,8,9,12 };
	int arr2[] = { 2,3,4,7,9,11,13 };
	int len1 = 7;
	int len2 = 7;
	// 两个子数组分别有序。 怎样将他们合并成一个有序数组。 
	int *arr = malloc(sizeof(int) * (len1 + len2));

	int index1 = 0;
	int index2 = 0;

	int total_index = 0;
	while (index1 < len1 && index2 < len2) {
		if (arr1[index1] < arr2[index2]) {
			arr[total_index++] = arr1[index1++];
		}
		else {
			arr[total_index++] = arr2[index2++];
		}
	}
	while (index1 < len1) {
		arr[total_index++] = arr1[index1++];
	}

	while (index2 < len2) {
		arr[total_index++] = arr2[index2++];
	}

	for (int i = 0; i < total_index; i++) {
		printf("%d\t", arr[i]);
		//printf("%d\t", arr[total_index]);
	}

}


int main(void) {

	test1();

	return 0;
}