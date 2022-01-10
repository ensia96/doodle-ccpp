#include <stdio.h>

int main()
{
    /* <= 주석 처리할 구간을 아무렇게나 지정 가능
    // int : 32비트(4바이트), 정수를 담는 데 쓰임
    int a = 5;
    int b = 3;

    int hap = a + b;
    int cha = a - b;
    int gop = a * b;
    int mok = a / b;
    int namuji = a % b;

    printf("%d + %d = %d\n", a, b, hap);
    printf("%d - %d = %d\n", a, b, cha);
    printf("%d * %d = %d\n", a, b, gop);
    printf("%d / %d = %d\n", a, b, mok);
    printf("%d %% %d = %d\n", a, b, namuji);
    */

    /*
    // float : 32비트(4바이트), 실수를 담는 데 쓰임

    // [부호][10의 지수][숫자] -> 3.14 = 314 * 10**-2 -> [+][-2][314]

    // 실수 저장 공간이 부족해서 계산할 때 오차가 발생함
    // -> 이를 최소화하기 위해 double 이라는 자료형을 많이 사용함

    // float 의 유래
    // 부동 소수점(floating point) -> 부동(떠다니는 = float)
    // 소수점이 떠다닌다 = 10의 지수에 따라서 소수점의 위치가 바뀜

    float a = 9.8;
    float b = 3.14;

    float hap = a + b;
    float cha = a - b;
    float gop = a * b;
    float mok = a / b;

    printf("%f + %f = %f\n", a, b, hap);
    printf("%f - %f = %f\n", a, b, cha);
    printf("%f * %f = %f\n", a, b, gop);
    printf("%f / %f = %f\n", a, b, mok);
    */

    // double : 64비트(8바이트), 실수를 담는 데 쓰임
    // 저장 공간이 더 커서, float 형에 비해서 더 정확함

    // double 의 유래
    // float 형의 '2배' 크기라서

    double a = 9.8;
    double b = 3.14;

    double hap = a + b;
    double cha = a - b;
    double gop = a * b;
    double mok = a / b;

    printf("%f + %f = %f\n", a, b, hap);
    printf("%f - %f = %f\n", a, b, cha);
    printf("%f * %f = %f\n", a, b, gop);
    printf("%f / %f = %f\n", a, b, mok);
}
