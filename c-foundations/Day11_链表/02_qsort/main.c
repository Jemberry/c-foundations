#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

// Student

void test1() {
	// qsort： 系统提供的一个排序函数。 
	// 系统为我们写好了排序。但是现在有一个问题
	// 这个排序应该具有可扩展性。 

	// 现在，我有一个结构体数组，我也想用它排。 
	// 函数指针。 
}

void select_sort(int arr[], int len) {
	// 选择排序： 每一轮，将最小的选到前面。 
	for (int i = 0; i < len; i++) {
		// 需要将剩下的数组中的最小值，找出来。 
		int min_index = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}

		int tmp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = tmp;
		//         min=2
		//        i
		//{  1,4,10,5,98,8,7,65,35,15,1256,56,30};
	}

}

void test2() {
	int arr[] = { 10,30,1,5,98,8,7,65,35,15,1256,56,4 };
	//{ 1,4,10,5,98,8,7,65,35,15,1256,56,30 };

	int len = ARR_LEN(arr);
	select_sort(arr, len);

	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int compare_int(const void *a, const void *b) {

	// a b 是什么东西。
	// 这两个指针，始终是数据的指针。  数据的类型int； 数据的指针是int *
	int *p1 = a;
	int *p2 = b;

	//return *p1 - *p2;
	return *p2 - *p1;
}

void test3() {
	printf("test3=============\n");
	int arr[] = { 10,30,1,5,98,8,7,65,35,15,1256,56,4 };

	// void qsort(void *base, size_t num, size_t size, 
	// int (*compare)(const void *, const void *));
	
	// 用来排序。，任意类型都要能排。 
	qsort(arr, ARR_LEN(arr), sizeof(int), compare_int);

	for (int i = 0; i < ARR_LEN(arr); i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}

typedef struct {
	int id;
	char name[20];
	int chinese;
	int math;
	int english;
}Student;

// 如果这是一个结构体。这个结构体，想按照 id排序。 

int compare_student_by_id(const void *a, const void *b) {
	// a b 是数据的指针。 
	// 数据是结构体。 数据的指针是 结构体指针。 

	Student *p_s1 = a;
	Student *p_s2 = b;
	//Student s1 = *(Student *)a;

	return  p_s1->id - p_s2->id;
}


int compare_student_by_score(const void *a, const void *b) {
	Student *p_s1 = a;
	Student *p_s2 = b;
	
	// 如果想按照语文分数排。 降序排、 
	// 语文相同，按数学排。 
	// 数学相同，按英语排。 
	if (p_s1->chinese == p_s2->chinese) {
		if (p_s1->math == p_s2->math) {
			return p_s1->english - p_s2->english;
		}

		return p_s1->math - p_s2->math;
	}
	// 不要使劲嵌套if   可以反着想一下条件。 
	return  p_s1->id - p_s2->id;
}

int compare_student_by_score2(const void *a, const void *b) {
	Student *p_s1 = a;
	Student *p_s2 = b;

	// 如果想按照语文分数排。 降序排、 
	// 语文相同，按数学排。 
	// 数学相同，按英语排。 
	if (p_s1->chinese != p_s2->chinese) {
		return p_s2->chinese - p_s1->chinese;
	}

	// 说明，相等。 
	if (p_s1->math != p_s2->math) {
		return p_s2->math - p_s1->math;
	}

	return p_s2->english - p_s1->english;
	// 不要使劲嵌套if   可以反着想一下条件。 
}

void test4() {

	Student s1 = { 1, "zhangsan1", 90, 70, 70 };
	Student s2 = { 9, "zhangsan9", 90, 80, 75 };
	Student s3 = { 3, "zhangsan3", 80, 60, 80 };
	Student s4 = { 4, "zhangsan4", 70, 80, 69 };
	Student s5 = { 2, "zhangsan2", 100, 40, 80 };
	Student s6 = { 7, "zhangsan7", 95, 90, 81 };
	Student s7 = { 6, "zhangsan6", 80, 100, 80 };

	Student stu_arr[7] = { s1, s2, s3, s4, s5, s6, s7 };

	//qsort(stu_arr, 7, sizeof(Student), compare_student_by_id);
	qsort(stu_arr, 7, sizeof(Student), compare_student_by_score2);

	for (int i = 0; i < 7; i++) {
		printf("%d----%s----%d----%d------%d\n",
			stu_arr[i].id, stu_arr[i].name, stu_arr[i].chinese,
			stu_arr[i].math, stu_arr[i].english);
	}

}

int compare_string(const void *a, const void *b) {
	// 函数中。 拿到的参数时是什么

	// a    b: 
	// 数据是 char *;  数据的指针：  char **
	char **pp1 = a;
	char **pp2 = a;
	//**pp1; 
	// return strcmp(*pp1, *pp2);

	char *str1 = *(const char **)a;
	char *str2 = *(const char **)b;
	return strcmp(str1, str2);
}

void test5() {
	// 对于 字符串数组 的排序。 
	// 指针数组。 

	char *str_arr[] = { "abc", "ab", "ad", "b", "bc", "dd" };

	// 现在想排这个字符串数组的序，怎么排？

	// 数组里面，装的指针。 
	qsort(str_arr, 6, sizeof(char *), compare_string);
}

int main(void) {

	//test2();
	//test3();
	test4();

	return 0;
}