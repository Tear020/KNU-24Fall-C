#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
	int a, b, c; //������������ �����
	int d; // �Ǻ���
	char fx[100];

	printf("������������ �Է��ϼ���(����� 1�̾ �Է�, ex : 1x^2+1x+3) : ");
	scanf_s("%s", fx, sizeof(fx));
	if (sscanf_s(fx, "%dx^2+%dx+%d", &a, &b, &c) == 3)
	{
		d = b * b - 4 * a * c;

		if (d > 0)
		{
			int x1, x2;
			printf("�� ���� �Ǳ� ����\n");
			x1 = -b + sqrt(d) / (2 * a);
			x2 = -b - sqrt(d) / (2 * a);

			printf("�� ���� �Ǳ� : %d, %d\n", x1, x2);
		}
		else if (d == 0)
		{
			int x;
			printf("�߱��� ����\n");
			x = -b / (2 * a);
			printf("%d", x);
		}
		else
		{
			printf("����� ����\n");
		}
	}

	else
	{
		printf("�߸��� �Է��Դϴ�.");
	}
}