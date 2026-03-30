#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void test1() {
	// 生成随机数后，花色和点数的问题。 
	const char suit_arr[4] = { 'C', 'D','H', 'S' };

	int random_suit_index = rand() % 4;   // 0  1  2   3

	suit_arr[random_suit_index];
}


void test2() {
	// 第一次掷的时候：
	//   如果点数之和为 7 或 11 则获胜；
	//   如果点数之和为2、3或12则落败；
	//   其他情况下的点数之和称为“目标”，继续投掷两个骰子。
	// 在后续的投掷中：
	//   如果玩家再次掷出“目标”点数则获胜；
	//   如果掷出7则落败；
	//   其他情况都忽略，继续投掷两个骰子。
	// 在每一局游戏结束时，程序都要询问用户是否再玩一次，
	// 如果用户输入的回答不是 y 或 Y ，那么就结束游戏，程序此时要打印显示胜败的次数。
	srand(time(NULL));

	int win_count = 0;
	int loss_count = 0;
	char input_flag = 'y';

	while (input_flag == 'y' || input_flag == 'Y') {
		int val1 = rand() % 6 + 1;
		int val2 = rand() % 6 + 1;
		int first_roll_sum = val1 + val2;
		bool has_res = false;

		printf("first_roll_sum = %d\n", first_roll_sum);
		if (first_roll_sum == 7 || first_roll_sum == 11) {
			// 说明赢了。 
			printf("you win! \n");
			win_count++;
			// break   continue  return 
			has_res = true;
		}else if (first_roll_sum == 2 || first_roll_sum == 3
			|| first_roll_sum == 12) {
			// 说明输了。 
			printf("you loss.\n");
			loss_count++;
			has_res = true;
		}

		// 假设这是后续的流程，后续的投掷。 
		while (!has_res){
			int next_val1 = rand() % 6 + 1;
			int next_val2 = rand() % 6 + 1;

			if (next_val1 + next_val2 == first_roll_sum) {
				// 说明，赢了。 
				printf("next roll win.sum = %d\n", next_val1 + next_val2);
				win_count++;
				break;
			}
			else if (next_val1 + next_val2 == 7) {
				// 说明输了。 
				printf("next roll loss.sum = %d\n", next_val1 + next_val2);
				loss_count++;
				break;
			}
		}
		
		printf("play again?(yY/n)\n");
		scanf(" %c", &input_flag);

		while (getchar() != '\n');
		//if (input_flag != 'y' && input_flag != 'Y') {
		//	break;
		//}
	}

	printf("you win count = %d\n", win_count);
	printf("you loss count = %d\n", loss_count);

	// 注意，在循环内部，怎样控制循环。 
	// 有时候，想跳出一层循环，有时候，想跳出两层循环。 
}

void test3(int *p) {
	//num = 999;
	//*p = 888;
}


int main(void) {
	test2();

	return 0;
}