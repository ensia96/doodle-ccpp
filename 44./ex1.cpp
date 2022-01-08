// 상수 : 변하지 않는 수
// 변수 : 변할 수 있는 수 (상수의 반댓말)
// const, 매크로, enum

#include <stdio.h>

int main()
{
    /*
    float a = 3.14159;

    float b = 3.14159 * 2;
    */

    /*
    float pi = 3.14159;

    float a = pi;
    float b = pi * 2;
    */

    /*
    float pi = 3.14159;

    float a = pi;
    float b = pi *= 2; // <- 누가 실수했다고 가정, pi에는 2가 곱해지고, b에는 그 결과가 대입됨

    printf("π = %.2f\n", pi);
    */

    // 위와 같은 실수를 예방하는 방법
    const float PI = 3.14159;
    // const = 이 자료는 상수다.(변수 아님)
    // 메모리에 실제로 저장은되지만, 값을 바꿀 수는 없음
    // C 언어에서는 일반적으로 상수 이름을 대문자로 정함

    float a = PI;

    // float b = PI *= 2; // 바꿀 수 없는 값이라는 것을 알리는 오류가 뜸 -> 실행하면 빌드 오류
    // PI = 0; // 상수로 선언했기 때문에, 값을 바꿀 수 없음

    printf("π = %.2f\n", PI);
    printf("&π = %d\n", &PI); // 실제 주소가 출력됨
}
