#include <stdio.h>

struct Vector{
	int x, y, z;
};

int hap(struct Vector v1, struct Vector v2)
{
	printf("������ ���� (%d, %d, %d) \n", v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
int cha(struct Vector v1, struct Vector v2)
{
	printf("������ ���� (%d, %d, %d) \n", (v1.x - v2.x), (v1.y - v2.y), (v1.z - v2.z));
}
int out(struct Vector v1, struct Vector v2)
{
	printf("������ ������ (%d, %d, %d) \n", (v1.y*v2.z - v1.z*v2.y), (v1.z*v2.x -v1.x*v2.z), (v1.x*v2.y - v1.y*v2.x));
}
int in(struct Vector v1, struct Vector v2)
{
	printf("������ ������ vec1 * vec2 = %d\n", v1.x * v2.x + v1.y *v2.y + v1.z + v2.z );
}

int main()
{
	struct Vector v1, v2;
	int co;
	int whi = 1;

	while (whi)
	{
		printf("ù��° ����(x, y, z) : ");
		scanf_s("%d, %d, %d", &v1.x, &v1.y, &v1.z);

		printf("�ι�° ����(x, y, z) : ");
		scanf_s("%d, %d, %d", &v2.x, &v2.y, &v2.z);
		printf("�Էµ� ù��° ���� : %d, %d, %d\n", v1.x, v1.y, v1.z);
		printf("�Էµ� �ι�° ���� : %d, %d, %d\n", v2.x, v2.y, v2.z);
		printf("\n---------------------------------------\n");
		printf("1. ������ ��\n");
		printf("2. ������ ��\n");
		printf("3. ������ ����\n");
		printf("4. ������ ����\n");
		printf("5. ����\n");
		printf("\n---------------------------------------\n");

		printf("��� �Է� : ");
		scanf_s("%d", &co);

		switch (co)
		{
		case 1:
			hap(v1, v2); break;
		case 2:
			cha(v1, v2); break;
		case 3:
			out(v1, v2); break;
		case 4:
			in(v1, v2); break;
		default: whi = 0;
		}
	}
	printf("���α׷� ����\n");
}