#include <stdio.h>

int main()
{
	int N;
	printf("피라미드 몇 층 : ");
	scanf_s("%d", &N);
	printf("%d 층 피라미드\n", N);
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < 2*i + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}