#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void)
{
	double x = 0;
	double y = 0;
	int r = 1;
	double z = 0;
	double pi = 0;
	int num = 0;

	int count = 0, circle = 0; //점 개수, 원 안의 점 개수

	srand(time(NULL));

	while (count < 1000000000)
	{
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;
		pi = ((double)circle / (double)count) * 4;
		z = (double)sqrt(pow(x, 2) + pow(y, 2));
		count++;

		if (z < r)
		{
			circle++;
		}
		if (count % 10000000 == 0)
		{
			printf("%d%%진행.. 원주율 : %.6lf ", count / 10000000, pi);
			num++;
			for (int i = 0; i < num / 5; i++)
			{
				printf("■");
			}

			for (int j = 0; j < 20 - num / 5; j++)
			{
				printf("□");
			}
			printf("\n");
		}

	}
}