// 포인터 (pointer) : 다른 변수의 주소를 저장하는 변수
// 주소 (address) : 기억 장치의 특정 위치를 나타내는 숫자

#include <stdio.h>

int main()
{
    int a = 20;

    int* ptr_a; // 가리킬 변수의 자료형 + '*' + 이름
    ptr_a = &a; // &a -> a의 주소, &main -> main의 주소, &c -> c의 주소

    /*
    char c = 'h';
    char* ptr_c;

    printf("%d\n", ptr_a);
    */

    printf("a의 값 : %d\n", a);
    printf("a의 주소값 : %d\n", &a);
    printf("ptr_a에 저장된 값 : %d\n", ptr_a);
    printf("ptr_a가 가리키는 변수의 값 : %d\n", *ptr_a); // 선언에서 사용한 *과는 다른 *임
}
