#include <stdio.h>

int fac(int num);

int main()
{
	int input, res;
	printf("����� ���丮�� �� �Է� : ");
	scanf_s("%d", &input);
	res = fac(input);
	printf("%d", res);
	return 0;
}

int fac(int num)
{
	int result = 0;
	
	if (num == 1)
		return 1;
	
	result = num * fac(num - 1);

	return result;
}