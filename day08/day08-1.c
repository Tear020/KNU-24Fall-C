#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	char* pstr = str;
	char temp;
	

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf_s("%s", str, sizeof(str));

	for (int i = 0; i < strlen(str) / 2; i++)
	{
		temp = pstr[strlen(str) - (1 + i)];
		pstr[strlen(str) - (i + 1)] = pstr[i];
		pstr[i] = temp;

	}
	printf("�������� ���ڿ� : ");
	for (int j = 0; j < strlen(str); j++)
		printf("%c", pstr[j]);

	return 0;
}