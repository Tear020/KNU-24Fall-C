#include <stdio.h>

struct Vector{
	int x, y, z;
};

int hap(struct Vector v1, struct Vector v2)
{
	printf("벡터의 합은 (%d, %d, %d) \n", v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
int cha(struct Vector v1, struct Vector v2)
{
	printf("벡터의 차는 (%d, %d, %d) \n", (v1.x - v2.x), (v1.y - v2.y), (v1.z - v2.z));
}
int out(struct Vector v1, struct Vector v2)
{
	printf("벡터의 외적은 (%d, %d, %d) \n", (v1.y*v2.z - v1.z*v2.y), (v1.z*v2.x -v1.x*v2.z), (v1.x*v2.y - v1.y*v2.x));
}
int in(struct Vector v1, struct Vector v2)
{
	printf("벡터의 내적은 vec1 * vec2 = %d\n", v1.x * v2.x + v1.y *v2.y + v1.z + v2.z );
}

int main()
{
	struct Vector v1, v2;
	int co;
	int whi = 1;

	while (whi)
	{
		printf("첫번째 벡터(x, y, z) : ");
		scanf_s("%d, %d, %d", &v1.x, &v1.y, &v1.z);

		printf("두번째 벡터(x, y, z) : ");
		scanf_s("%d, %d, %d", &v2.x, &v2.y, &v2.z);
		printf("입력된 첫번째 벡터 : %d, %d, %d\n", v1.x, v1.y, v1.z);
		printf("입력된 두번째 벡터 : %d, %d, %d\n", v2.x, v2.y, v2.z);
		printf("\n---------------------------------------\n");
		printf("1. 벡터의 합\n");
		printf("2. 벡터의 차\n");
		printf("3. 벡터의 외적\n");
		printf("4. 벡터의 내적\n");
		printf("5. 종료\n");
		printf("\n---------------------------------------\n");

		printf("명령 입력 : ");
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
	printf("프로그램 종료\n");
}