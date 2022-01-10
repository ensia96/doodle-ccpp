// 1. 다음 프로그램의 출력 결과는?

#include <stdio.h>

typedef int Point[2];
typedef Point* PointPtr;

int main()
{
    Point p = { 3, 4 }; // int p[2] = { 3, 4 };
    PointPtr pp = &p;   // Point* pp = &p;

    printf("%d %d %d\n", **pp, (*pp)[0], (*pp)[1]); // 3, 3, 4
    // **pp == *(*pp) == *&p == p == p[0]
    // (*pp)[0] == p[0]
    // (*pp)[1] == p[1]
}
