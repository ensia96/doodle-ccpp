/*
    1. arr == &arr[0] -> ptr == &ptr[a]
    2. *ptr == ptr[0]
    3. ptr + 1 == ptr + sizeof(*ptr)
*/

#include <stdio.h>

int main()
{
    int arr[3] = { 1, 2, 3 };

    printf("arr = %d\n", arr);
    printf("arr + 1 = %d\n", arr + 1); // + 4

    printf("&arr = %d\n", &arr);
    printf("&arr + 1 = %d\n", &arr + 1); // + 12 -> sizeof(arr) == 4 * 3 == 12
}
