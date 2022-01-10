#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    /*
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("%d\n", sum);
    */

    int i, sum;
    for (i = 1, sum = 0; i <= n; sum += i, i++)
        ;

    printf("%d\n", sum);
}
