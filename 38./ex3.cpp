#include <stdio.h>

int main()
{
    // char* name = "Doodle"; // 문자열을 char 자료형에 대한 포인터로 선언

    typedef char* String;

    String name = "Doodle"; // == char* name = "Doodle";

    /*
    typedef int MYINT;
    MYINT age;
    // 이렇게 불필요한 형을 정의하는 것은 좋지 않음
    */

    printf("이름 : %s\n", name);
}
