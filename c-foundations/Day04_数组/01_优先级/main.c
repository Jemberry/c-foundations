#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {

	int ch;

	//while ((ch = getchar()) != '\n') {
	//	printf("%c-----%d\n", ch, ch);
	//}
	//printf("while loop end.\n");

	while (ch = getchar() != '\n') {
		printf("%c-----%d\n", ch, ch);
	}

	printf("while loop end.\n");

	// *p++
	// ++*p
	// (*p)++;
	// ++(*p)


	return 0;
}