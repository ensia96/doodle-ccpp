#include <stdio.h>

int main()
{
    int arr[3][3] = { 0 };

    printf("%d\n", &arr[0][0]); // -> arr[0][0]의 주소

    printf("%d\n", arr[0] + 1);  // -> + 4
    printf("%d\n", &arr[0] + 1); // -> + 12
    printf("%d\n", arr + 1);     // -> + 12
    printf("%d\n", &arr + 1);    // -> + 36
}
