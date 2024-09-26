#include <stdio.h>
#include <stdlib.h> //malloc 사용 위해

int main()
{
	int N;
	int* stud_num; //학번
	char** name; //이름
	int* score; //점수

	printf("학생 몇 명 : ");
	scanf_s("%d", &N);
	stud_num = (int*)malloc(N * sizeof(int));
	name = (char**)malloc(N * sizeof(char*));
	score = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < N; i++)
	{

		printf("학번 : ");
		scanf_s("%d", &stud_num[i]);

		printf("이름 : ");
		scanf_s("%s", name[i], sizeof(name));

		printf("점수 : ");
		scanf_s("%d", &score[i]);
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d %s %d\n", stud_num[i], name[i], score[i]);
	}

	free(stud_num);
	free(score);
	free(name);

	//malloc
	//scanf_s
	//printf()

	return 0;
}
