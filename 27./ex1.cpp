#include <stdio.h>

int main()
{
    int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

    /*
    printf("%d\n", sizeof(arr));       // 24 = 4 * 3 * 2
    printf("%d\n", sizeof(arr[0]));    // 12 = 4 * 3
    printf("%d\n", sizeof(arr[0][0])); // 4  = 4
                                       // arr[0][0] == (arr[0])[0]
    */

    printf("%d\n", &arr);
    printf("%d\n", &arr[0]);
    printf("%d\n", &arr[0][0]);
}
