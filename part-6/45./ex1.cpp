#include <stdio.h>

#define PI 3.14159

// 일반적인 식에 대해서도 매크로를 사용할 수 있음
#define PRINT_HELLO printf("Hello, World!");
// #define PRINT HELLO printf("Hello, World!"); // 매크로 이름은 무조건 붙여서 써야됨

int main()
{
    PRINT_HELLO
}
