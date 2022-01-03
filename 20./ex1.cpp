#include <stdio.h>

int main()
{
    /*
    int a1, a2, a3, a4, a5, a6, ...;
    a1 = 1;
    a2 = 2;
    a3 = 3;
    a4 = 4;
    a5 = 5;
    ...

    printf("%d\n", a1);
    printf("%d\n", a2);
    printf("%d\n", a3);
    printf("%d\n", a4);
    printf("%d\n", a5);
    ...
    */

    // 배열의 가장 기본적인 선언 방식 (이름[크기])
    // -> [2][5][7][3][-1]
    // 실제 기억 장치 상에서도 연속적으로 저장됨
    // 값을 하나씩 집어넣을 수 있는 형태, 각 칸을 변수처럼 사용 가능
    int a[5];

    /*
    [    ][    ][    ][    ][    ]
     a[0]  a[1]  a[2]  a[3]  a[4]

    a[0] = 2;
    a[1] = 3;
    a[2] = 7;
    a[3] = 6;
    a[4] = 8;

    printf("%d\n", a[0]);
    printf("%d\n", a[1]);
    printf("%d\n", a[2]);
    printf("%d\n", a[3]);
    printf("%d\n", a[4]);
    */

    for (int i = 0; i <= 4; i++) {
        a[i] = i * 5;
    }

    for (int i = 0; i <= 4; i++) {
        printf("%d\n", a[i]);
    }
}
