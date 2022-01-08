#include <stdio.h>

/*
struct Time {
    int h, m, s; // 시, 분, 초
};

// 1시간 = 60분 = 3600초
// 1분 = 60초
// 1시간 22분 48초 = (1 * 3600 + 22 * 60 + 48)초

int totalSec(Time t)
{
    return 3600 * t.h + 60 * t.m + t.s;
}

// C++ 에서는 이렇게 서로 밀접한 관계의 구조체와 함수를 하나로 합칠 수 있음
// -> 구조체에 함수를 집어넣을 수 있음
// -> 전체적으로 코드 구성이 깔끔해짐
// -> 가독성이 좋아짐
// -> C++ 에서는 확실히 가능, C 언어는 버전에 따라 다름
*/

struct Time {
    int h, m, s;

    int totalSec() // Time 구조체의 멤버 함수(메서드)
    {
        return 3600 * h + 60 * m + s; // 구조체 내의 다른 멤버 변수에 바로 접근할 수 있음
    }
};

int main()
{
    Time t = { 1, 22, 48 };

    printf("%d\n", t.totalSec());
}
