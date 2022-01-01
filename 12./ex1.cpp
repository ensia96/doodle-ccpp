#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    /*
    if (n % 2 == 0) {
        printf("n은 짝수\n");
    } else {
        printf("n은 홀수\n");
    }
    */

    // 0, 1

    if (n % 2) {
        printf("n은 홀수\n");
    } else {
        printf("n은 짝수\n");
    }
}
