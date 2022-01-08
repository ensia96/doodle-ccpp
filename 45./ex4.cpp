#include <stdio.h>

#define FOR(I, S, E) for (int I = S; I <= E; I++) // 코드 길이가 짧아짐, 오타 등의 실수를 예방 가능
#define LOOP while (true)                         // 무한 루프도 재정의 가능

// 매크로 사용은 취향껏

int main()
{
    /*
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    */

    FOR(i, 1, 10)
    {
        printf("%d ", i);
    }

    LOOP
    {
        printf("*");
    }
}
