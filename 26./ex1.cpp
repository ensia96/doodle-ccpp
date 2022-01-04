#include <stdio.h>

int main()
{
    int arr[3] = { 1, 2, 3 };
    int* ptr = arr;

    for (int i = 0; i < 3; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // arr[i] == *(arr + i) == *(ptr + i) == *(i + ptr) == i[ptr] == ptr[i]
    // a[b] = *(a + b)

    for (int i = 0; i < 3; i++) {
        printf("%d ", i[ptr]); // 신기하긴 해도, 엄청 헷갈리기 때문에 실무에선 ㄴㄴ!
    }
    printf("\n");
}
