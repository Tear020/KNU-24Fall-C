#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define Max_topping 10000

// topping_len�� �迭 topping�� �����Դϴ�.
int solution(int topping[], size_t topping_len) {
    int left_t[Max_topping + 1] = { 0, }; //0~10000 ���� ����
    int right_t[Max_topping + 1] = { 0, }; //0~10000 ���� ����
    int left_type = 0; //���� ���� ����
    int right_type = 0; //������ ���� ����
    int answer = 0;

    for (int i = 0; i < topping_len; i++) //������ ���� ��
    {
        int top_n = topping[i]; //i��° �ڸ��� �ִ� ���� ��ȣ�� �������

        if (right_t[top_n] == 0) right_type++; //ó�� �Դ� ������ �� ���� ���� +1
        right_t[top_n]++; //���� (top_n) ��°�� ���� +1
    }

    for (int i = 0; i < topping_len; i++) //���� ���� ������ �ϳ��� ���
    {
        int top_n = topping[i];
        right_t[top_n]--; // ����, (top_n) ��°�� ���� -1

        if (right_t[top_n] == 0) right_type--; // ������ top_n�� ������ ������ �� ������ ������ 0�̸� ���� ���� -1

        if (left_t[top_n] == 0) left_type++; //��, ó�� �Դ� ������ �� ���� ���� +1
        left_t[top_n]++; // ��, (top_n) ��°�� ���� +1

        if (left_type == right_type) answer++;
    }

    return answer;
}