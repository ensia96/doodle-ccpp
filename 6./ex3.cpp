// 형 변환 : 자료형을 다른 자료형으로 바꾸는 작업

#include <stdio.h>

int main()
{
    int math = 90, korean = 95, english = 96;
    int sum = math + korean + english;
    double avg = (double)sum / 3; // 변수 sum의 자료형을 잠시동안 double로 취급함

    printf("%f\n", avg); // 93.666667 -> 93.000000(변수 sum에 대해, 형 변환을 하지 않으면)
}

// 정수 / 정수 = 정수
// 실수 / 정수 = 실수
// 정수 / 실수 -> 하지 마세요
// 실수 / 실수= 실수

// 정수 + 정수 = 정수
// 정수 + 실수 = 실수
// 실수 + 실수  실수
// -> -. *에서도 마찬가지
