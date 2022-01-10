// 팩토리얼
// 5! = 5 * 4 * 3 * 2 * 1 = 120
// for 문을 이용해서도 구현 가능
// n! = n * (n - 1)!
// 팩토리얼의 정의 속에 자기 자신 (팩토리얼) 이 있음 -> 재귀적임

#include <stdio.h>

// 매개 변수 n -> n! 반환
int factorial(int n)
{
    if (n == 1) // 1! = 1 -> 1 대신 0으로 설정해도 됨
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    // printf("%d\n", factorial(3));
    // printf("%d\n", factorial(10)); // n이 조금만 커져도 결과값이 엄청나게 커짐
    printf("%d\n", factorial(20)); // int 범위 벗어남
}
