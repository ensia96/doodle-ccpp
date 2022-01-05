#include <stdio.h>

/*
int noMeaning()
{
    printf("first\n");
    return 1; // 값을 반환하는 즉시 함수가 종료됨
    // 때문에 아래 코드들은 실행이 안 됨

    printf("second\n");
    return 2;
}

int main()
{
    int a;
    a = noMeaning();

    printf("반환된 값 : %d\n", a);
}
*/

void noMeaning() // void 형 함수
{
    printf("first\n");
    return; // return 을 만나도 함수가 종료됨

    printf("second\n");
    return;
}

int main()
{
    noMeaning();
}
