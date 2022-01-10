/*
    1. arr == &arr[0] -> ptr == &ptr[a]
    2. *ptr == ptr[0] -> *arr == arr[0]
    3. ptr + 1 == ptr + sizeof(*ptr)
*/

#include <stdio.h>

int main()
{
    int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

    /*
    int arrr[5] = { 1, 2, 3, 4, 5 };
    int* pptrr = arrr;

    pptrr[3];
    */

    int(*ptr)[3] = arr; // == &arr[0]

    // 1. ptr[i] == arr[i]
    //           == *(ptr + i)
    //           -> ptr + i = ptr + 12 * i == arr[i]
    // 2. ptr[i][j] == arr[i][j] -> 1이 성립하므로 당연히 성립
    // -> ptr == arr

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}
