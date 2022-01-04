#include <stdio.h>

int main()
{
    int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

    for (int(*row)[3] = arr; row < arr + 2; row++) {
        // row == &arr[0], row + i == row + sizeof(arr[i])
        for (int* col = *row; col < *row + 3; col++) {
            // col == &*row == &row[0], col + i == col + sizeof(arr[i][j])
            printf("%d ", *col);
        }
        printf("\n");
    }
}
