//Haoheng Duan
//z5248147
//29/09/2019
#include <stdio.h>
int main(void) {
	int no1;
	int no2;
	int total;
	printf("Please enter two integers: ");
	scanf("%d %d", &no1, &no2);
	total = no1 + no2;
	if (no1 < 0 && no1 >= -10) {
		printf("negative ");
	} else {
	}
	if (no1 == 0) {
		printf("zero");
	} else if (no1 > 10 || no1 < -10) {
		printf("%d", no1);
	} else if (no1 == 1 || no1 == -1) {
		printf("one");
	} else if (no1 == 2 || no1 == -2) {
		printf("two");
	} else if (no1 == 3 || no1 == -3) {
		printf("three");
	} else if (no1 == 4 || no1 == -4) {
		printf("four");
	} else if (no1 == 5 || no1 == -5) {
		printf("five");
	} else if (no1 == 6 || no1 == -6) {
		printf("six");
	} else if (no1 == 7 || no1 == -7) {
		printf("seven");
	} else if (no1 == 8 || no1 == -8) {
		printf("eight");
	} else if (no1 == 9 || no1 == -9) {
		printf("nine");
	} else if (no1 == 10 || no1 == -10) {
		printf("ten");
	}
	printf(" + ");
	if (no2 < 0 && no2 >= -10) {
		printf("negative ");
	} else {
	}
	if (no2 == 0) {
		printf("zero");
	} else if (no2 > 10 || no2 < -10) {
		printf("%d", no2);
	} else if (no2 == 1 || no2 == -1) {
		printf("one");
	} else if (no2 == 2 || no2 == -2) {
		printf("two");
	} else if (no2 == 3 || no2 == -3) {
		printf("three");
	} else if (no2 == 4 || no2 == -4) {
		printf("four");
	} else if (no2 == 5 || no2 == -5) {
		printf("five");
	} else if (no2 == 6 || no2 == -6) {
		printf("six");
	} else if (no2 == 7 || no2 == -7) {
		printf("seven");
	} else if (no2 == 8 || no2 == -8) {
		printf("eight");
	} else if (no2 == 9 || no2 == -9) {
		printf("nine");
	} else if (no2 == 10 || no2 == -10) {
		printf("ten");
	}
	printf(" = ");
	if (total < 0 && total >= -10) {
		printf("negative ");
	} else {
	}
	if (total == 0) {
		printf("zero");
	} else if (total > 10 || total < -10) {
		printf("%d\n", total);
	} else if (total == 1 || total == -1) {
		printf("one\n");
	} else if (total == 2 || total == -2) {
		printf("two\n");
	} else if (total == 3 || total == -3) {
		printf("three\n");
	} else if (total == 4 || total == -4) {
		printf("four\n");
	} else if (total == 5 || total == -5) {
		printf("five\n");
	} else if (total == 6 || total == -6) {
		printf("six\n");
	} else if (total == 7 || total == -7) {
		printf("seven\n");
	} else if (total == 8 || total == -8) {
		printf("eight\n");
	} else if (total == 9 || total == -9) {
		printf("nine\n");
	} else if (total == 10 || total == -10) {
		printf("ten\n");
	}
	return 0;
}
