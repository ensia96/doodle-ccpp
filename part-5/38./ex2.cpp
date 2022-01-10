#include <stdio.h>

int main()
{
    // int point[2] = { 3, 4 }; // 점의 좌표를 저장하는 배열 -> [x, y]

    typedef int Pair[2];   // 점의 좌표 자체를 Pair라는 이름의 자료형으로 만들기
    Pair point = { 3, 4 }; // == int point[2] = {3, 4};

    printf("(%d, %d)\n", point[0], point[1]); // 좌표를 순서쌍 형태로 출력
}
