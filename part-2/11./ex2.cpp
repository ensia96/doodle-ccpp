// 논리 연산자 (그리고, 또는, ...)
// &&, ||, ! => and, or, not

#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);

    bool p = a >= 1 && a <= 10; // == (a >= 1) && (a <= 10) => 1 <= a <= 10
    bool q = a == 3 || a == 7;
    bool r = !q;

    printf("%d\n", p);
    printf("%d\n", q);
    printf("%d\n", r);
}
