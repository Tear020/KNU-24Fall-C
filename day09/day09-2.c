#include <stdio.h>

struct Product {
	int id;
	char name[10];
	int price;
};

void printProduct(struct Product pd)
{
	printf("상품 ID : %d\n", pd.id);
	printf("상품명 : %s\n", pd.name);
	printf("가격 : %d\n", pd.price);
}

int main()
{
	struct Product pd[5];

	for (int i = 0; i < 5; i++)
	{
		printf("상품 정보를 입력하세요 (입력 중단은 id에 0 입력)\n");
		printf("상품 ID : ");
		scanf_s("%d", &pd[i].id);
		if (pd[i].id == 0)
		{
			printf("\n<< 입력된 상품 목록 >>\n");
			for (int j = 0; j < i; j++)
				printProduct(pd[j]);
			return 0;
		}
		printf("상품명 : ");
		scanf_s("%s", &pd[i].name, sizeof(10));
		printf("가격 : ");
		scanf_s("%d", &pd[i].price);
		printf("\n");
	}

	printf("\n<< 입력된 상품 목록 >>\n");
	for (int j = 0; j < 5; j++)
		printProduct(pd[j]);

	return 0;
}