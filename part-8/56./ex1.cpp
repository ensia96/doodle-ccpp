// 생성자 : 객체가 생성될 때 자동으로 호출되는 함수
// 소멸자 : 객체가 소멸될 때 자동으로 호출되는 함수

#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() // 생성자
              // 일반적인 메서도와 비슷한 형태, 반환하는 자료형을 명시하지는 않음
    {
        cout << "생성자가 호출되었다!!" << endl;
    }
    ~MyClass() // 소멸자
    {
        cout << "소멸자가 호출되었다!!" << endl;
    }
};

// 생성자나 소멸자를 따로 선언하지 않으면?
// -> 그래도 생성자가 호출됨 -> ? -> 기본 생성자, 기본 소멸자가 있음
// -> 기본적으로 호출이 되는 생성자, 소멸자가 있다는 뜻 -> 아무 내용도 없음;

// MyClass globalObj; // 전역 범위에 MyClass 객체 생성 (== global object)

void testLocalObj()
{
    cout << "testLocalObj함수 시작!!" << endl;
    MyClass localObj;
    cout << "testLocalObj함수 끝!!" << endl;
    // localObj -> main 함수가 실행된 후, testLocalObj 함수가 실행되기 전에 생성
    //          -> testLocalObj 함수가 완전히 종료된 후에 소멸함

    // 지역 변수로 선언되면, 선언되는 시점에 바로 객체가 생성되고, 객체가 속한 지역이 끝나는 순간 소멸함
    // -> 현재 예시에서는 testLocalObj 가 지역이 됨
}

int main()
{
    cout << "main 함수 시작!!" << endl;
    testLocalObj();
    cout << "main 함수 끝!!" << endl;
    // globalObj 는 main 함수가 실행되기 전에 생성되고, main 함수가 완전히 종료된 후에 소멸함
}
