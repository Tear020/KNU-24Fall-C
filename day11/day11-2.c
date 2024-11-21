#include <stdio.h>
#include <math.h>

int main(void)
{
	char fx[100];
	int a, b, c; //ax^2+bx+c
	a = 1, b = 0, c = 1; // x^2+1
	int start, end, range;
	printf("적분의 시작 값을 입력하세요(fx = x^2 + 1) : ");
	scanf_s("%d", &start);
	printf("적분할 끝 값을 입력하세요 : ");
	scanf_s("%d", &end);
	printf("시행할 최대 구간을 입력하세요(2^n) : ");
	scanf_s("%d", &range);

	printf("밑변  : %d\n", end - start);
	printf("x가 end 일 때 %d\n", (end * end * a) + (end * b) + c);
	printf("x가 start 일 때 %d\n", (start * start * a) + (start * b) + c);

}