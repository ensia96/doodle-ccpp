// 배열 포인터 : 배열을 가리키는 포인터
// 포인터 배열 : 포인터들이 저장된 배열

#include <stdio.h>

int main()
{
    /*
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    // int(*ptr)[4]; // 배열 포인터를 선언하는 방식
    int* ptr[4]; // 포인터 배열을 선언하는 방식

    ptr[0] = &a;
    ptr[1] = &c;
    ptr[2] = &d;
    ptr[3] = &b;

    printf("%d %d %d %d\n", *ptr[0], *ptr[1], *ptr[2], *ptr[3]);
    */

    int arr[4] = { 1, 2, 3, 4 };
    int* ptr[4];

    for (int i = 0; i < 4; i++) {
        ptr[i] = &arr[i];
    }

    for (int i = 0; i < 4; i++) {
        printf("%d ", *ptr[i]);
    }
    printf("\n");
}
