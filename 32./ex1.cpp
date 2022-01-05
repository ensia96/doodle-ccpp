// return : 돌려주다, 반환

#include <stdio.h>

/*
int main()
{
    int a;
    a = printf("aaaaa\n");

    printf("%d\n", a); //  출력된 문자 수
}
*/

// void == 아무것도 반환하지 않는 함수임을 나타냄

// 2개의 매개 변수(정수)의 합을 반환
int plus(int a, int b)
// int = 정수의 합은 정수이므로, 정수를 반환하는 함수임을 나타내야 함
{
    return a + b;
}

int main()
// main 함수는 조금 특별한 함수임
// 코드를 다 실행해도 반환하는 값이 없다면 자동으로 0을 반환함
{
    int sum = plus(3, 5); // 함수 실행 결과가 대입됨
    printf("%d\n", sum);

    // return 0; // <- 생략되어 있다고 보면 됨
}
