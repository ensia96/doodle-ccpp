#include <stdio.h>

int main()
{
    // array
    // int arr[5] = { 3, 1, 4, 1, 5 }; // -> [3][1][4][1][5]
    int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 }; // 이렇게, 선언하면 배열 크기를 자동으로 지정

    /*
    for (int i = 0; i <= 4; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    */

    // for (int i = 0; i <= sizeof(arr) / sizeof(int) - 1; i++) { // 배열의 크기로 지정할 수 있음
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
