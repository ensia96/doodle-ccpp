// 매개 변수가 있는 매크로

#include <stdio.h>

// #define SQUARE(X) X* X // x * x 에 별명을 붙여준 것이 SQUARE(X) 라는 뜻

//#define SQUARE(X) (X * X) // 애초에 이렇게 선언하면 아래 문제가 생기지 않음

#define SQUARE(X) ((X) * (X)) // 이렇게 매개 변수가 있는 매크로를 선언할 때는, 괄호를 잘 쳐주는 것이 중요함

/*
int square(int a)
{
    return a * a;
}
*/

int main()
{
    int a;
    scanf("%d", &a);

    // printf("%d\n", a * a);
    // printf("%d\n", SQUARE(a)); // 괄호 안에 있는 값이 x가 됨 -> SQUARE(a) 가 a * a 로 대체됨

    /*
    printf("%d\n", 100 / SQUARE(a));   // 이상한 값이 출력됨 -> 100 / SQUARE(a) == 100 / a * a == (100 / a) * a
    printf("%d\n", 100 / (SQUARE(a))); // <- 이렇게 해결할 수는 있음
    */

    /*
    printf("%d\n", 100 / SQUARE(a)); // == 100 / (a * a)
    */

    /*
    printf("%d\n", SQUARE(a - 1));   // 이상한 값이 출력됨 -> SQUARE(a - 1) == (a - 1 * a - 1) == a - a - 1 = -1
    printf("%d\n", SQUARE((a - 1))); // <- 이렇게 해결할 수는 있음
    */

    printf("%d\n", SQUARE(a - 1));
}
