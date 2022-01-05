// call-by-value : 값에 의한 호출
// call-by-reference : 참조에 의한 호출

#include <stdio.h>

/*
int main()
{
    int a, b;

    scanf("%d%d", &a, &b);

    // a = b;
    // b = a;
    // 이렇게 작성해서는 a와 b를 바꿀 수 없음

    int tmp = a;
    a = b;
    b = tmp;
    // 임시 변수를 둬서 값을 따로 빼두는 방식

    printf("a = %d, b = %d\n", a, b);
}
*/

/*
void swap(int x, int y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int a, b;

    scanf("%d%d", &a, &b);

    swap(a, b); // 이렇게 하면 안 바뀜
    // 함수에 a, b의 값만 전달되기 때문
    // -> call-by-value(값만 넘겨줌)
    // x, y는 정상적으로 바뀌지만, a, b는 그대로

    printf("a = %d, b = %d\n", a, b);
}
*/

/*
void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int a, b;

    scanf("%d%d", &a, &b);

    swap(&a, &b); // 이렇게 하면 바뀜
    // 함수에 주소가 전달되므로, 실제 주소에 저장된 값이 바뀌게 됨
    // -> call-by-reference(실제 변수를 참조)

    printf("a = %d, b = %d\n", a, b);
}
*/

void swap(int& x, int& y) // 이 문법(참조 변수)은 C++ 에서만 지원함
{
    int tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int a, b;

    scanf("%d%d", &a, &b);

    swap(a, b);

    printf("a = %d, b = %d\n", a, b);
}
