// 변수 관련 기본 문법
// 범위 기반 for 문, reference 변수 등

#include <iostream>

using namespace std;

int main()
{
    /*
    int a = 10; // 초기화

    int a;
    a = 10;

    // C 언어에서는 둘 다 같은 표현
    // -> C++ 에서는 조금 다르게 작동함
    // -> 때문에, 선언 / 대입과 초기화를 구분지어줘야 함
    */

    /*
    int a(10); // C++ 스타일의 초기화 문법
    // a = 5;     // a(5) 형태로 대입할 수는 없음 -> 해당 구문만 보고는 함수 호출인지 아닌지를 알 수 없음
    int b(a);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    */

    int a(10);
    int b(a + 5);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
