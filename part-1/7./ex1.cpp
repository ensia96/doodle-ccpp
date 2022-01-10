#include <stdio.h>

int main()
{
    /*
    int a, b;

     scanf("%d%d", &a, &b); // & : 포인터
    // 입력을 읽고, 띄어쓰기 등으로 구분된 내용을 각각 %d 로 인식함

    int hap = a + b;
    int cha = a - b;
    int gop = a * b;
    int mok = a / b;

    printf("%d + %d = %d\n", a, b, hap);
    printf("%d - %d = %d\n", a, b, cha);
    printf("%d * %d = %d\n", a, b, gop);
    printf("%d / %d = %d\n", a, b, mok);
    */

    float a, b;

    scanf("%f%f", &a, &b);

    /*
    float hap = a + b;
    float cha = a - b;
    float gop = a * b;
    float mok = a / b;

    printf("%f + %f = %f\n", a, b, hap);
    printf("%f - %f = %f\n", a, b, cha);
    printf("%f * %f = %f\n", a, b, gop);
    printf("%f / %f = %f\n", a, b, mok);
    */

    printf("%f + %f = %f\n", a, b, a + b);
    printf("%f - %f = %f\n", a, b, a - b);
    printf("%f * %f = %f\n", a, b, a * b);
    printf("%f / %f = %f\n", a, b, a / b);
}
