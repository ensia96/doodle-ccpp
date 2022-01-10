#include <stdio.h>

int main()
{
    int a = 10;
    int* ptr_a = &a; // == int* ptr_a; ptr_a = & a;

    printf("ptr_a의 값 : %d\n", ptr_a);
    printf("ptr_a + 1의 값 : %d\n", ptr_a + 1);
    // 기억 장치는 1바이트를 최소 단위로 취급
    // 주소값에 1을 더하면, 가리키고 있는 변수의 자료형의 크기를 더함
    // 위 예시의 경우, int 자료형의 크기는 4바이트이므로, 4가 더해짐
}
