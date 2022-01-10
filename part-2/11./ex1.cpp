// 비교 연산사

#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    /*
    // 2 > 3 -> 거짓
    // 참 : 1, 거짓 : 0

    int p = a > b;
    int q = a < b;
    int r = a == b; // == : 같다
    */

    // bool : 진리값 저장용 변수 (1바이트)
    bool p = a > b;
    bool q = a < b;
    bool r = a == b;

    // a >= b : a는 b보다 크거나 같다
    // a <= b : a는 b보다 작거나 같다
    // a != b : a는 b가 아니다

    printf("%d\n", p);
    printf("%d\n", q);
    printf("%d\n", r);
}
