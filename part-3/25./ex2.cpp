#include <stdio.h>

int main()
{
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // printf("arr의 값 : %d\n", arr); // arr == &arr[0]
    // arr + i == &arr[0] + i == &arr[i]
    for (int i = 0; i < 10; i++) {
        printf("&arr[%d] = %d\n", i, &arr[i]);
        printf("arr + %d = %d\n", i, arr + i);
    }
    // 배열을 선언하면, 실제 기억 장치에서 연속된 공간을 할당함
    // 그리고, 이러한 공간을 자료형의 크기를 기준으로 나눠서 처리함
    // 위 코드를 통해, 각 인덱스의 주소가 int 자료형의 크기인 4만큼 차이난다는 것을 알 수 있음
}
