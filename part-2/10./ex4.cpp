// 전치와 후치

#include <stdio.h>

int main()
{
    int a = 10;
    int b;

    /*
    printf("=== 전치 증가 연산 ===\n");

    b = ++a; // 전치 : a를 1 증가시킨 후에 b에 대입
    // a++;
    // b = a;

    printf("a : %d\n", a);
    printf("b : %d\n", b);
    */

    printf("=== 후치 증가 연산 ===\n");

    b = a++; // 후치 : a를 b에 대입한 후에 1 증가
    // b = a;
    // a++;

    printf("a : %d\n", a);
    printf("b : %d\n", b);
}
