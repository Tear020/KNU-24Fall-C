#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int main()
{
	int array[SIZE][SIZE];

	fillRandom(array); //�迭 ���� �ʱ�ȭ
	printArray(array); //�迭 ���
	movePointer(array); // �����͸� �̿��� �̵�

	return 0;
}

void fillRandom(int array[SIZE][SIZE])
{
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			array[i][j] = rand() % 20 + 1;
		}
	}
}

void printArray(int array[SIZE][SIZE])
{
	printf("�迭 ��� : \n");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

void movePointer(void* array)
{
	int x = 0, y = 0, count = 0;
	void* cur = array;
	
	while (1)
	{
		printf("���� ��ġ : (%d, %d), �迭�� �� : %d\n", x,y, *(int*) cur);
		
			count += *(int*)cur;
			if (count >= 100) break;
				
			x = count / 10;
			y = count % 10;
			(int*)cur += *(int*)cur;
	}

	printf("�� �̻� �̵��� �� �����ϴ�.\n");
	printf("���� ��ġ: (%d, %d), �迭�� �� : %d\n", x, y, *(int*)cur);
	
}