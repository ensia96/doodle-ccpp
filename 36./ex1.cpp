#include <stdio.h>

/*
int main()
{
    int arr[4] = { 1, 2, 3, 4 };

    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
}
*/

/*
int arr[4] = { 1, 2, 3, 4 };

void printArr()
{
    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
}

int main()
{
    printArr();
}
*/

// call-by-value : 값만
// call-by-reference : 참조

void printArr(int arr[4]) // -> call-by-reference | int arr[4] == int *arr
{
    for (int i = 0; i < 4; i++) {
        // printf("%d ", arr[i]);
        arr[i] *= 2; // arr[i] == *(arr + i)
    }
}

int main()
{
    int arr[4] = { 1, 2, 3, 4 };

    printArr(arr); // arr == &arr[0]

    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
}
