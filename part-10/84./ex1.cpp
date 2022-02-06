// 이번 시간에는, 지난 시간에 이어서 다운캐스팅에 대해 더 알아볼 것임
// -> static_cast, dynamic_cast 로 다운캐스팅을 일으킬 수 있음

// static_cast : 정적
// dynamic_cast : 동적

// static_cast -> 정적 형 변환 -> 컴파일 시간(compile time) 에 형 변환이 일어남
// dynamic_cast -> 동적 형 변환 -> 실행 시간(run time) 에 형 변환이 일어남

// 실행 시간(run time) : 프로그램이 실제로 실행되는 도중

// RTTI (Run Time Type Information/Identification) : 실행 시간에 자료형에 대한 정보를 알 수 있게 해주는 기능

#include <iostream>

using namespace std;

/*
class Base { // 다형 클래스
             // -> 가상 함수가 하나라도 포함되어 있는 클래스를 다형 클래스라고 부름
             // -> 다형성에 대한 내용은 나중에 더 자세히 다뤄볼 것임
public:
    virtual void f() { }
    int x;
};
*/

class Base {
public:
    virtual void f() { }
    // int x;
    int x = 10; // 출력을 위해 초기값 지정
};

class Derived : public Base {
public:
    void f() { } // 메서드 오버라이딩
    // int y;
    int y = 20; // 출력을 위해 초기값 지정
};

int main()
{
    /*
    Base* b = new Derived;
    Derived* d = static_cast<Derived*>(b); // b가 가리키는 대상의 자료형을 컴파일 시간에는 알 수 없다는 게 문제였음
                                           // -> 실행 시간에 b가 가리키는 대상의 자료형을 알아내야 할 때가 있음
                                           // -> 컴파일러는 b가 가리키는 대상의 자료형을 모름
                                           // -> 실행 시간에 타입 정보를 알아낼 방법은 있음 (RTTI)
                                           // -> C++ 자체에는, 기본적으로는 이런 기능이 없음
                                           // -> C++ 내부적으로 RTTI 가 무조건 필요한 경우가 있음 (가상 함수를 사용할 때)
    b->f();                                // Base::f() 가 가상 함수가 아니면 정적 바인딩이 일어나서 Base::f() 가 실행됨
                                           // -> 컴파일러가 b를 Base 포인터로 인식하고, Base::f() 를 호출하게 함
                                           // -> Base::f() 가 가상 함수이면, 동적 바인딩이 일어남
                                           // -> 실행 시간에 포인터가 가리키고 있는 대상을 확인하게 된다는 뜻
                                           // -> 가상 함수라는 기능을 위해서라도 RTTI 기능이 필요하다는 뜻
    */
    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    // Base 클래스에 가상 함수가 없으면 4, 8이 출력됨
    // -> Base::f() 를 가상 함수로 바꿔주면 8, 12가 출력됨 (내 컴퓨터에선 16, 16이 출력됨)
    // -> Base 클래스와 Derived 클래스의 크기가 4바이트씩 늘어남 (컴파일러마다 다를 수 있음)
    // -> 여기서 추가된 4바이트 크기의 공간에는 어딘가를 가리키는 포인터(p) 가 저장됨
    // -> p가 가리키고 있는 위치에는 클래스에 대한 정보가 저장되어 있음
    // -> Base 객체는 p와 자신의 고유한 멤버인 x를 포함함 (p = 4byte, x = 4byte / 8byte)
    // -> Derived 객체는 Base 클래스에서 상속받은 p, x와 자신의 고유한 멤버인 y를 포함함 (y = 4byte / 12byte)

    // Base* b = new Derived; => Base* b 는 new Derived::Base 부분(p, x) 만 가리킴
    // -> p, x, y가 저장된 12바이트 크기의 공간 중 p, x가 저장된 8바이트 크기의 공간에만 접근할 수 있음
    // -> p가 가리키고 있는 공간에는 Derived 클래스에 대한 정보가 저장되어 있음
    // -> 이를 통해, 현재 b가 가리키고 있는 객체의 자료형이 Derived 임을 확인할 수 있음
    // -> 이것이 RTTI 기능의 기본적인 원리임
    // -> p가 가리키고 있는 공간에 대해서는 나중에 살펴볼 예정 (많이 복잡하기 때문)

    // dynamic_cast 로 다운캐스팅을 하려면, 실행 시간에 타입에 대한 정보를 알 수 있어야 함
    // -> RTTI 기능이 수행될 수 있는 조건이 충족된 상태에서만 가능
    // -> 다형 클래스가 아닌 클래스에 대해서는 RTTI 가 지원되지 않음
    // -> Base 에서 Derived 로 다운캐스팅을 한다고 하면, Base 는 다형 클래스여야 함

    int* a = (int*)new Base;             // Base 객체(8byte) 를 가리키는 포인터를 int 포인터(4byte) 로 변환
    cout << a[0] << " " << a[1] << endl; // new Base 로 생성된 객체를 배열로 보고, 각 인덱스(멤버) 를 출력

    int* b = (int*)new Derived;                         // Derived 객체의 크기는 12바이트임
    cout << b[0] << " " << b[1] << " " << b[2] << endl; // new Derived 로 생성된 객체를 3칸 짜리 배열로 취급

    int* c = (int*)new Derived;
    cout << c[0] << " " << c[1] << " " << c[2] << endl;

    delete a;
    delete b;
    delete c;

    // a[0], a[1] 출력 결과 : 임의의 정수(포인터 p), x의 값
    // -> 내 컴퓨터에서 출력된 결과를 확인해보면 a[1] 에는 1, a[2] 에는 x가 저장되어 있음
    // -> 아마 8바이트 주소 체계를 사용하기 때문인 것 같음

    // 출력된 값을 확인해보면, b[0] == c[0] 이지만, a[0] != b[0] 임
    // -> a[0], b[0], c[0] 모두 포인터임
    // -> Base 객체와 Derived 객체의 시작 위치에 저장된 포인터가 서로 다른 곳을 가리키고 있음
    // -> 그리고, 그 포인터들이 가리키고 있는 위치에는 각 클래스에 대한 정보가 들어있음
    // -> *a[0] = Base 클래스에 대한 정보 / *b[0], *c[0] = Derived 클래스에 대한 정보
}
