/* 1.
 * 정수를 하나 매개 변수로 받아
 * 그 수가 짝수이면 0, 홀수이면 1을 반환하는 함수를 작성해보세요.
 */

#include <stdio.h>

int parity(int n) // parity == 홀짝성(홀수 짝수 여부)
{
    /*
    // 작성
    if (n % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
    */

    /*
    if (n % 2 == 0) {
        return 0;
    }
    return 1;
    */

    // return n % 2;           // 음수 홀수면 -1을 반환함
    return (n % 2 + 2) % 2; // 이렇게 작성하면 음수 홀수여도 1을 반환함
}

int main()
{
    printf("%d\n", parity(5));
    printf("%d\n", parity(-3));
    printf("%d\n", parity(6));
}
