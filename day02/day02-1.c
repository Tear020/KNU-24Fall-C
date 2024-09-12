#include <stdio.h>

int main(void)
{
	int a;
	double num1, num2;
	printf("원하는 기능을 입력하세요.\n");
	printf("1.더하기 2.빼기 3.곱하기 4.나누기\n");
	printf("기능 : ");
	scanf_s("%d", &a);

	printf("숫자 1을 입력하세요 : ");
	scanf_s("%lf", &num1);

	printf("숫자 2를 입력하세요 : ");
	scanf_s("%lf", &num2);

	if (a == 1)
	{
		printf("%lf + %lf = %lf", num1, num2, num1 + num2);
	}
	else if (a == 2)
	{
		printf("%lf - %lf = %lf", num1, num2, num1 - num2);
	}
	else if (a == 3)
	{
		printf("%lf * %lf = %lf", num1, num2, num1 * num2);
	}
	else if (a == 4)
	{
		printf("%lf / %lf = %lf", num1, num2, num1 / num2);
	}
	else
	{
		printf("잘못된 입력입니다.");
	}

	return 0;

}