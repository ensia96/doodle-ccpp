// 제어문 - 반복문(while)
// -> 일정한 조건을 만족하는 동안 코드를 반복

#include <stdio.h>

int main()
{
    int i = 1; // 15 -> 아예 반복문이 수행되지 않음

    while (i <= 10) {
        printf("%d\n", i);
        i++;
    }
}
