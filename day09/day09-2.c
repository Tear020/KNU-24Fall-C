#include <stdio.h>

struct Product {
	int id;
	char name[10];
	int price;
};

void printProduct(struct Product pd)
{
	printf("��ǰ ID : %d\n", pd.id);
	printf("��ǰ�� : %s\n", pd.name);
	printf("���� : %d\n", pd.price);
}

int main()
{
	struct Product pd[5];

	for (int i = 0; i < 5; i++)
	{
		printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� id�� 0 �Է�)\n");
		printf("��ǰ ID : ");
		scanf_s("%d", &pd[i].id);
		if (pd[i].id == 0)
		{
			printf("\n<< �Էµ� ��ǰ ��� >>\n");
			for (int j = 0; j < i; j++)
				printProduct(pd[j]);
			return 0;
		}
		printf("��ǰ�� : ");
		scanf_s("%s", &pd[i].name, sizeof(10));
		printf("���� : ");
		scanf_s("%d", &pd[i].price);
		printf("\n");
	}

	printf("\n<< �Էµ� ��ǰ ��� >>\n");
	for (int j = 0; j < 5; j++)
		printProduct(pd[j]);

	return 0;
}