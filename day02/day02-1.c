#include <stdio.h>

int main(void)
{
	int a;
	double num1, num2;
	printf("���ϴ� ����� �Է��ϼ���.\n");
	printf("1.���ϱ� 2.���� 3.���ϱ� 4.������\n");
	printf("��� : ");
	scanf_s("%d", &a);

	printf("���� 1�� �Է��ϼ��� : ");
	scanf_s("%lf", &num1);

	printf("���� 2�� �Է��ϼ��� : ");
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
		printf("�߸��� �Է��Դϴ�.");
	}

	return 0;

}