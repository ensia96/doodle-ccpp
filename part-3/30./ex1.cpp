#include <stdio.h>

int main()
{
    int arr[3][3] = { 0 };

    printf("%d\n", &arr); // -> arr의 시작 주소
    printf("%d\n", arr);  // -> arr의 시작 주소 -> arr[0]의 시작 주소
    printf("%d\n", *arr); // -> arr[0]의 주소 -> arr[0][0]의 주소

    printf("%d\n", &arr[0]); // -> arr[0]의 시작 주소
    printf("%d\n", arr[0]);  // -> arr[0]의 시작 주소 -> arr[0][0]의 주소
    printf("%d\n", *arr[0]); // -> arr[0][0]의 주소 -> arr[0][0]의 주소에 저장된 값 == arr[0][0] == 0

    printf("%d\n", &arr[0][0]); // -> arr[0][0]의 주소

    printf("%d\n", arr[0][0]); // -> arr[0][0] == 0
}
