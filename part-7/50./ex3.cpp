#include <iostream>

using namespace std;

// void swap(int* a, int* b) // 전에는 call-by-value 로 구현하면 안 되서 포인터를 활용했음
void swap(int& a, int& b) // 마지막엔 참조를 활용하도록 바꾸기도 했음
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    /*
    // int& a;
    // 참조 변수 : 포인터와 비슷한 개념
    // 어떤 변수를 가리킴 -> call-by-refernce 가능
    // 선언 방식이 다름

    // 포인터
    // int* p = &a;
    //*p = 10;

    int a(5);
    int& p = a; // 참조 변수
    p = 10;

    cout << p << endl;
    cout << a << endl;
    */

    /*
    int a(5), b(7);

    swap(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    */

    /*
    int a(5);
    int& r1 = a;
    int& r2 = 3;     // 3 == 메모리에 저장되어 있지 않음 -> 포인터던 참조 변수던 상수를 가리킬 수는 없음
    int& r3 = a * a; // a * a == 메모리에 저장되어 있지 않음 -> 참조 변수로 가리킬 수 없음

    // 2011년에 C++ 이 많이 바뀜 -> r-value 가 추가됨
    // 등호의 왼쪽에 있으면 l-value, 오른쪽에 있으면 r-value
    // r-value = 수정할 수 없는 값
    // l-value = 수정할 수 있는 값

    // 숫자 3은 바꿀 수 없음 -> 규칙이기 때문
    // a * a = 4; // 변수에는 값을 대입할 수 있어도, 식 자체에 값을 대입할 수는 없음
    // r-value 는 이러한 바꿀 수 없는 값들에 대한 참조를 제공함
    */

    int a(5);
    // int&& r1 = a; // a는 바꿀 수 있는 값이어서 저장할 수 없음
    int&& r2 = 3;
    int&& r3 = a * a;
    // 함숫값도 수정할 수 없는 값이므로 r-value 로 참조할 수 있음
    // r-value 의 필요성에 대해서는 나중에
}
