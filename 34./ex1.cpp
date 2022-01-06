// prototype : 원형, 시제품
// 함수의 원형을 미리 적어놓고, 정의는 나중에 하는 것
// 미리 함수의 형태만 간략하게 적어주는 것

#include <stdio.h>

/*
// 걷기
void walk(int distance)
{
    printf("%dcm를 걸었습니다.\n", distance);
}

// 돌기
void rotate(int angle)
{
    printf("%d도 회전했습니다.\n", angle);
}

void drawSquare()
{
    for (int i = 1; i <= 4; i++) {
        walk(10);
        rotate(90);
    }
}

int main()
{
    drawSquare();
}
*/

/*
// 이렇게 순서를 바꾸면, 호출할 수 없음
int main()
{
    drawSquare();
}

void drawSquare()
{
    for (int i = 1; i <= 4; i++) {
        walk(10);
        rotate(90);
    }
}

// 아래와 비슷한 상황

int main()
{
    a = 50;

    int a;
}

// 아래처럼 해도 안됨

void drawSquare() { }

void rotate(int angle) { }
*/

// 걷기
// void walk(int distance);
void walk(int); // 이렇게 매개 변수의 자료형만 정해줘도 됨

// 돌기
// void rotate(int angle);
void rotate(int);

void drawSquare();

// 이렇게 위에서 함수 자료형, 매개 변수 등의 형태만 지정
// 기능 구현은 하지 않은 상태여도, 컴파일러는 함수 형태를 인식함
// 이렇게 프로토타입은, 어떤 순서로 선언해도 상관 없음

int main()
{
    drawSquare(); // 아래에 함수 정의가 있으므로 호출해도 됨
}

// 이렇게 아래에서 함수 내용을 정의 (기능 구현)

// 걷기
// void walk(int distance)
void walk(int distance)
{
    printf("%dcm를 걸었습니다.\n", distance);
}

// 돌기
void rotate(int angle)
{
    printf("%d도 회전했습니다.\n", angle);
}

void drawSquare()
{
    for (int i = 1; i <= 4; i++) {
        walk(10);
        rotate(90);
    }
}

// 프로토타입의 장점 -> 필수는 아니지만, 코드를 더 쉽게 볼 수 있게 해주는 요소임
// 1. 함수끼리 서로 호출하는 상황에서 발생하는 문제를 해결할 수 있음 (정의 순서가 자유로워짐)
// 2. 함수 선언 순서를 굳이 신경쓰지 않아도 됨
// 3. 프로토타입만 보고, 어떤 함수가 정의되어 있는지를 쉽게(한눈에) 파악할 수 있음
