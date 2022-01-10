// 최대, 최소

#include <stdio.h>

int main()
{
    int n;
    int arr[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    printf("%d\n", max);

    /*
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (min > arr[i])
            min = arr[i];
    }
    printf("%d\n", min);
    */
}
