#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	char *temp;
	temp = str;

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf_s("%s", str, sizeof(str));

	for (int i = 0; i < strlen(str) / 2; i++)
	{
		temp = str[strlen(str) - (i + 1)];
		str[strlen(str) - (i + 1)] = str[i];
		str[i] = temp;
	}
	printf("%s", str);
}