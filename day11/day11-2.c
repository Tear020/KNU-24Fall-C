#include <stdio.h>
#include <math.h>

float f(float x) 
{
    return -log10(1.0 / x) + sin(x);
}

float juckbun(float start, float end, int n) {
    float h = (end - start) / n; //구간 폭
    float sum = 0.5 * (f(start) + f(end)); //사다리꼴 넓이

    for (int i = 1; i < n; i++) {
        sum += f(start + (i * h));
    }

    return sum * h;  // 적분값 반환
}

int main(void) {
    float start, end, n;
    printf("적분의 시작 값을 입력하세요(fx = -log10(1.0 / x) + sin(x)) : ");
    scanf_s("%f", &start);
    printf("적분할 끝 값을 입력하세요 : ");
    scanf_s("%f", &end);
    printf("시행할 최대 구간을 입력하세요 (2^n) : ");
    scanf_s("%f", &n);

    for (int i = 0; i <= (int)n; i++) {
        int gugan = (int)pow(2, i);
        float result = juckbun(start, end, gugan);  // 적분 계산
        printf("구간 %d 적분결과 : %f\n", gugan, result);
    }

    return 0;
}
