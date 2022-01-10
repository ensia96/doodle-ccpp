// typedef -> ty)e def -> type define
// 형을 정의

#include <stdio.h>

int main()
{
    // unsigned short int age; // 2바이트 크기의 부호가 없는 정수
    // -> usi age; // 이렇게, 기존에 있던 자료형에 새로운 이름을 붙이는 것이 typedef

    // int n = 20;
    typedef int Int32; // 정수 자료형의 크기를 표시해주도록 이름 바꾸기
    Int32 n = 20;      // int -> Int32

    printf("%d\n", n);
    printf("%d\n", sizeof(Int32));
}
