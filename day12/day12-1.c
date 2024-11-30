#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define Max_topping 10000

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int left_t[Max_topping + 1] = { 0, }; //0~10000 토핑 개수
    int right_t[Max_topping + 1] = { 0, }; //0~10000 토핑 개수
    int left_type = 0; //왼쪽 토핑 종류
    int right_type = 0; //오른쪽 토핑 종류
    int answer = 0;

    for (int i = 0; i < topping_len; i++) //동생만 먹을 때
    {
        int top_n = topping[i]; //i번째 자리에 있는 토핑 번호를 집어넣음

        if (right_t[top_n] == 0) right_type++; //처음 먹는 토핑일 때 토핑 종류 +1
        right_t[top_n]++; //동생 (top_n) 번째의 값에 +1
    }

    for (int i = 0; i < topping_len; i++) //형이 동생 토핑을 하나씩 뺏어감
    {
        int top_n = topping[i];
        right_t[top_n]--; // 동생, (top_n) 번째의 값에 -1

        if (right_t[top_n] == 0) right_type--; // 동생이 top_n번 토핑을 뺏겼을 때 토핑의 개수가 0이면 토핑 종류 -1

        if (left_t[top_n] == 0) left_type++; //형, 처음 먹는 토핑일 때 토핑 종류 +1
        left_t[top_n]++; // 형, (top_n) 번째의 값에 +1

        if (left_type == right_type) answer++;
    }

    return answer;
}