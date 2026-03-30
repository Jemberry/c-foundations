#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void test1() {
	// 比如，要生成 [50,100] 的随机数。  
	// (50,100) 的随机数。  
	srand(time(NULL));

	//rand() % (50); //  [0,49] + 50
	rand() % (51); // [0,50] + 50  ==> [50, 100]

	// [a,b]
	// rand() % （b-a+1） + a;
}


void test2() {
	// 扑克牌的花色（suit）有四种：梅花（Club）、方块（Diamond）、
	// 红心（Heart）、黑桃（Spade）
	// 扑克牌的点数（point）有13种，2~10，J，Q，K，A

	// 随机数 + 固定的数组。 
	// 从这个数组中，随机取出来东西。 
	const char suit_arr[4] = { 'C', 'D', 'H', 'S' };

	const char point_arr[13] = { '2', '3', '4', '5', '6', '7', '8', '9',
		'T', 'J', 'Q', 'K', 'A' };

	srand(time(NULL));

	int random_suit_index = rand() % 4;
	int random_point_index = rand() % 13;

	printf("%c%c\n",
		suit_arr[random_suit_index], point_arr[random_point_index]);
}

void test3() {
	const char suit_arr[4] = { 'C', 'D', 'H', 'S' };
	const char point_arr[13] = { '2', '3', '4', '5', '6', '7', '8', '9',
		'T', 'J', 'Q', 'K', 'A' };

	srand(time(NULL));

	int card_numer;
	printf("please input card_number you need: \n");
	scanf("%d", &card_numer);

	bool already_send_card[4][13] = { {0} };

	for (int i = 0; i < card_numer; i++) {
		int random_suit_index = rand() % 4;
		int random_point_index = rand() % 13;

		if (already_send_card[random_suit_index][random_point_index]) {
			// 说明，这张牌发过了。 
			printf("%c%c重复发送了\n",
				suit_arr[random_suit_index], point_arr[random_point_index]);
			i--;
			continue;
		}

		printf("%c%c\n",
			suit_arr[random_suit_index], point_arr[random_point_index]);
		already_send_card[random_suit_index][random_point_index] = true;
	}

}


void test4() {
	const char suit_arr[4] = { 'C', 'D', 'H', 'S' };
	const char point_arr[13] = { '2', '3', '4', '5', '6', '7', '8', '9',
		'T', 'J', 'Q', 'K', 'A' };

	srand(time(NULL));

	int need_card_numer;
	printf("please input card_number you need: \n");
	scanf("%d", &need_card_numer);

	bool already_send_card[4][13] = { {0} };

	int already_send_card_count = 0;

	while (already_send_card_count < need_card_numer) {
		int random_suit_index = rand() % 4;
		int random_point_index = rand() % 13;

		if (already_send_card[random_suit_index][random_point_index]) {
			continue;
		}
		//
		printf("%c%c\n",
			suit_arr[random_suit_index], point_arr[random_point_index]);
		already_send_card[random_suit_index][random_point_index] = true;
		already_send_card_count++;
	}

	// 做项目的时候，其实只是在将之前学习的东西糅合在一起使用。 
	// 所以，前期学习的时候，一定要注意练习。 
}

void test5() {
	// 猜大小。 0-100   
	srand(time(NULL));

	int random_value = rand() % 100;

	// 只能猜5次。 
	int already_guess_count = 0;
	int max_guess_count = 5;

	while (true) {
		printf("guess numer: \n");
		int guess_numer;
		scanf("%d", &guess_numer);

		if (guess_numer == random_value) {
			// 说明猜对了。 
			printf("guess right, number=%d\n", random_value);
			break;
		}
		else if (guess_numer < random_value) {
			printf("guess low\n");
		}
		else {
			printf("guess high\n");
		}

		already_guess_count++;
		if (already_guess_count >= max_guess_count) {
			printf("guess over max_count random_value=%d.\n", random_value);
			break;
		}
	}
}

int main(void) {

	//test2();
	//test3();
	//test4();
	test5();

	return 0;
}