/*
typedef int Pair[2];

Pair p; // == int p[2];
p[0] = 3;
p[1] = 4;

// 좌표를 나타내는 순서쌍인지 알아보기 힘듬 -> 직관적이지 않음
// -> 구조체 (struct) 를 사용해서 해결 가능
*/

/*
typedef struct {
    int x, y;
} Pair;

p.x = 3;
p.y = 4;

// 구조체는 이런 식으로, 여러 개의 변수를 하나로 묶은 형태임
*/

#include <stdio.h>

struct Point { // 구조체는 대체로, 전역 변수로 선언됨
    int x, y;
};

// 구조체에 대한 정보는 메모리에 저장되지 않음
// 대신, 어떤 자료가 선언될 때, 메모리가 위에 정의된 내용대로 할당됨

int main()
{
    /*
    typedef struct {
        int x, y;
    } Point;

    struct Point {
        int x, y;
    };

    // typedef struct { int x, y; } Point; // == struct Point { int x, y; };
    */

    Point p; // == struct { int x, y; } p;

    /*
    typedef int Int32;
    Int32 n; // == int n;
    */

    p.x = 3;
    p.y = 4;

    printf("(%d, %d)\n", p.x, p.y);
    printf("sizeof(p) = %d\n", sizeof(p)); // 메모리 상에는 4바이트 정수가 나란히 저장됨 -> 4 + 4 = 8
}
