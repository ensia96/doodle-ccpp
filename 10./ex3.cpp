// ++ --

#include <stdio.h>

int main()
{
    int a = 10;
    printf("원래 a는 %d였다...\n", a);
    a++; // a = a + 1;
         // a += 1;
    printf("1 증가해서 %d가 됐다...\n", a);
    a--; // a = a - 1;
         // a -= 1;
    printf("1 감소해서 %d가 됐다...\n", a);
}
