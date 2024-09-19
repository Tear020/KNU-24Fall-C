#include <stdio.h>

int prime_n(int number);

int main(void)
{
	int a;
	printf("소수인지 확인할 1보다 큰 양의 정수를 입력하세요 : ");
	scanf_s("%d", &a);
	if (a > 1) 
	{
		prime_n(a);
	}
	else
	{
		printf("1 보다 큰 자연수를 입력하세요.");
	}

	return 0;
}

int prime_n(int number)
{
	int k = 0;
	for (int i = 1; i < number; i++)
	{
		if (number % i == 0)
		{
			k += 1;
		}
	}
	
	if (k >= 2)
	{
		printf("소수가 아님");
		return 0;
	}
	else
	{
		printf("소수");
		return 1;
	}
}