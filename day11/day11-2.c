#include <stdio.h>
#include <math.h>

int main(void)
{
	char fx[100];
	int a, b, c; //ax^2+bx+c
	a = 1, b = 0, c = 1; // x^2+1
	float start, end, n;
	float base;
	float y = 0;
	printf("������ ���� ���� �Է��ϼ���(fx = x^2 + 1) : ");
	scanf_s("%f", &start);
	printf("������ �� ���� �Է��ϼ��� : ");
	scanf_s("%f", &end);
	printf("������ �ִ� ������ �Է��ϼ���(2^n) : ");
	scanf_s("%f", &n);

	//base = (end - start) / n;

	for (int i = 0; i <= (int)n; i++)
	{
		base = (end - start) / i;
		(start  + base) 
	}

	/*printf("�غ�  : %d\n", (end - start)/n);
	printf("x�� end �� �� %f\n", (end * end * a) + (end * b) + c);
	printf("x�� start �� �� %f\n", (start * start * a) + (start * b) + c);*/

}