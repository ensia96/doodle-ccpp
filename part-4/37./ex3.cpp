// 3. 다음 프로그램의 실행 결과는?

#include <stdio.h>

void rec(int n)
{
    if (n == 0)
        return;
    printf("%d", n);
    rec(n - 1);
    printf("%d", n);
}

int main()
{
    rec(5);
}

// 실행 결과 예측하기
// 5, 4, 3, 2, 1, 1, 2, 3, 4, 5
