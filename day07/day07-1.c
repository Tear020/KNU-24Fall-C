#include <stdio.h>

int main()
{
	int N;
	printf("�Ƕ�̵� �� �� : ");
	scanf_s("%d", &N);
	printf("%d �� �Ƕ�̵�\n", N);
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