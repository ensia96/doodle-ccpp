#include <stdio.h>

int max(int a, int b)
{
    /*
    if (a > b)
        return a;
    return b;
    */

    // 삼항 연산자 -> if-else 문을 내장한 형태,  ?와 :으로 구성됨
    // (조건) ? (조건이 참일 때의 값) : (조건이 거짓일 때의 값)

    return (a > b) ? a : b;
    // int r = (a > b) ? a : b; // 대입도 제대로 됨
}

#define MAX(A, B) ((((A) > (B))) ? (A) : (B))

int main()
{
    int a = 5, b = 10;

    printf("%d\n", MAX(a, b));
}
