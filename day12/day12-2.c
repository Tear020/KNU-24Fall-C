#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0; //���� Ƚ��
    int cur = n; //���� ��ġ

    while (cur > 1) //cur =1�� ������
    {
        if (cur % 2 == 0) //¦���� ��
        {
            cur = cur / 2; // �ڷ� 1/2��ŭ �̵�
        }
        else //Ȧ���� ��
        {
            cur--; // �ڷ� ���� �� ��
            ans++; // ���� Ƚ�� ����
        }
    }
    ans++; //1�̹Ƿ� 0���� ���� �� ��

    return ans;
}