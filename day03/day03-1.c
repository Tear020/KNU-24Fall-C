#include <stdio.h>

int prime_n(int number);

int main(void)
{
	int a;
	printf("소수인지 확일할 양의 정수를 입력하세요 : ");
	scanf_s("%d", &a);
	if (a > 0) 
	{
		prime_n(a);
	}
	else
	{
		printf("0 보다 큰 자연수를 입력하세요.0");
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
	}
	else
	{
		printf("소수");
	}
}