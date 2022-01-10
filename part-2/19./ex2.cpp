// 자연수 입력 : 12
// 1, 2, 3, 4, 6, 12,

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    /*
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d, ", i);
        }
    }
    */

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d, ", i);
        }
    }

    /*
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%d, ", i);
        }
    }

    printf("%d\n", n);
    */
}
