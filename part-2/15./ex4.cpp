#include <stdio.h>

int main()
{
    int n;

    do {
        printf("제발 0을 입력해주세요!!\n");
        scanf("%d", &n);
    } while (n != 0);

    printf("드디어 0을 입력하셨군요!\n");

    /*
    그냥 while 문을 활용하면, 아래처럼 n의 값이 정해지기도 전에 n과 0을 비교하게 됨
    논리적으로는 이상하지만, 정상적으로 동작함

    => 이렇게, do-while 문은 반복문 내부의 코드를 무조건 한 번은 실행시켜야 할 때 사용함

    while (n != 0) {
        scanf("%d", &n);
    }
    */
}
