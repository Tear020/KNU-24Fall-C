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

	fillRandom(array); //배열 렌덤 초기화
	printArray(array); //배열 출력
	movePointer(array); // 포인터를 이용한 이동

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
	printf("배열 출력 : \n");
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
		printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", x,y, *(int*) cur);
		
			count += *(int*)cur;
			if (count >= 100) break;
				
			x = count / 10;
			y = count % 10;
			(int*)cur += *(int*)cur;
	}

	printf("더 이상 이동할 수 없습니다.\n");
	printf("종료 위치: (%d, %d), 배열의 값 : %d\n", x, y, *(int*)cur);
	
}