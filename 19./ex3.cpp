// 일의 자릿수가 3, 6, 9인 경우 *
// 1 2 * 4 5 * 7 8 * 10 11 12 * 14 15 * 17 ...

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    /*
    for (int i = 1; i <= n; i++) {
        if (i % 10 % 3 == 0 && i % 10 / 3 > 0) {
            printf("* ");
        } else {
            printf("%d ", i);
        }
    }
    */

    for (int i = 1; i <= n; i++) {
        int k = i % 10;
        if (k == 3 || k == 6 || k == 9) {
            printf("* ");
        } else {
            printf("%d ", i);
        }
    }
    printf("\n");
}
