#include <stdio.h>
#include <math.h>

int main(void)
{
	char fx[100];
	int a, b, c; //ax^2+bx+c
	a = 1, b = 0, c = 1; // x^2+1
	int start, end, range;
	printf("������ ���� ���� �Է��ϼ���(fx = x^2 + 1) : ");
	scanf_s("%d", &start);
	printf("������ �� ���� �Է��ϼ��� : ");
	scanf_s("%d", &end);
	printf("������ �ִ� ������ �Է��ϼ���(2^n) : ");
	scanf_s("%d", &range);

	printf("�غ�  : %d\n", end - start);
	printf("x�� end �� �� %d\n", (end * end * a) + (end * b) + c);
	printf("x�� start �� �� %d\n", (start * start * a) + (start * b) + c);

}