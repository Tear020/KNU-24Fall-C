#include <stdio.h>

int fac(int num);

int main()
{
	int input, res;
	printf("계산할 팩토리얼 값 입력 : ");
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