#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
	int a, b, c; //이차방정식의 계수들
	int d; // 판별식
	char fx[100];

	printf("이차방정식을 입력하세요(계수가 1이어도 입력, ex : 1x^2+1x+3) : ");
	scanf_s("%s", fx, sizeof(fx));
	if (sscanf_s(fx, "%dx^2+%dx+%d", &a, &b, &c) == 3)
	{
		d = b * b - 4 * a * c;

		if (d > 0)
		{
			int x1, x2;
			printf("두 개의 실근 가짐\n");
			x1 = -b + sqrt(d) / (2 * a);
			x2 = -b - sqrt(d) / (2 * a);

			printf("두 개의 실근 : %d, %d\n", x1, x2);
		}
		else if (d == 0)
		{
			int x;
			printf("중근을 가짐\n");
			x = -b / (2 * a);
			printf("%d", x);
		}
		else
		{
			printf("허근을 가짐\n");
		}
	}

	else
	{
		printf("잘못된 입력입니다.");
	}
}