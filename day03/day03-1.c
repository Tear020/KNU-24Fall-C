#include <stdio.h>

int prime_n(int number);

int main(void)
{
	int a;
	printf("�Ҽ����� Ȯ���� 1���� ū ���� ������ �Է��ϼ��� : ");
	scanf_s("%d", &a);
	if (a > 1) 
	{
		prime_n(a);
	}
	else
	{
		printf("1 ���� ū �ڿ����� �Է��ϼ���.");
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
		printf("�Ҽ��� �ƴ�");
		return 0;
	}
	else
	{
		printf("�Ҽ�");
		return 1;
	}
}