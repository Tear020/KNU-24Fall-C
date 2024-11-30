#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0; //점프 횟수
    int cur = n; //현재 위치

    while (cur > 1) //cur =1일 때까지
    {
        if (cur % 2 == 0) //짝수일 때
        {
            cur = cur / 2; // 뒤로 1/2만큼 이동
        }
        else //홀수일 떄
        {
            cur--; // 뒤로 점프 한 번
            ans++; // 점프 횟수 증가
        }
    }
    ans++; //1이므로 0으로 점프 한 번

    return ans;
}