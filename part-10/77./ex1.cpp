// 이번 시간에는 오버라이딩과 정적 바인딩에 대해서 알아볼 것임 (어려움)

// override : 우선하다 (overwirte 아님)
// -> 상속받은 멤버와 고유한 멤버의 이름이 같으면, 고유한 멤버에 우선적으로 접근하게 됨

// overload : 오버로딩 -> override(상속) vs overload(함수)
// overwrite : 덮어쓰다 -> override(우선) vs overwrite(덮어쓰기)

#include <iostream>

using namespace std;

class Base {
public:
    int a = 10; // 변수를 선언한 후, 생성자에서 값을 초기화했을 때와 똑같이 동작함
                // -> Base() : a(10) { }; int a;
                // -> 생긴지 그렇게 오래되지는 않은 문법이라서, 비교적 옛날에 나온 버전에서는 지원하지 않을 수 있음

    // 멤버 변수 뿐만 아니라 멤버 메서드도 오버라이딩할 수 있음
    void Print()
    {
        cout << "From Base!!!" << endl;
    }
};

class Derived : public Base {
public:
    int a = 20; // 부모인 Base, 자식인 Derived 클래스 모두 a라는 멤버를 갖고 있는 상황임
                // -> 상속받은 a, 자신의 고유한 a가 있어서 모호성이 생기는데도 오류가 뜨지 않음
                // -> 또한, d.a 를 출력했더니, Derived 클래스에서 초기화된 값이 출력됨

    void Print()
    {
        cout << "From Derived!!!" << endl;
    }
};

int main()
{
    /*
    Base b;
    Derived d;

    cout << b.a << endl;          // 10
    cout << d.a << endl;          // 20
    cout << d.Base::a << endl;    // 10
    cout << d.Derived::a << endl; // 20

    // Base 클래스 내부에는 a라는 멤버 변수가 있음
    // -> Derived 클래스가 Base 클래스를 상속받은 상황임
    // -> Base 클래스에 있는 priavte 을 제외한 모든 멤버가 상속되어야 함
    //    (물론, priavte 멤버도 메모리 상에서 보면 실제로 상속되기는 함, 대신 접근할 수는 없음)
    // -> Derived 클래스는 Base 의 멤버 a를 상속받은 후에도, 자신만의 고유한 멤버 a도 따로 생성함
    // -> Derived 클래스 내에서 a라는 변수 이름에 대한 모호성이 생겨남 (오류가 나진 않음)
    // -> Derived 객체 d에 대해, d.a 라고 작성하면 Derived 클래스 고유의 a에 접근하게 됨
    // -> 물론, Derived 클래스 내부에서 'Base 에서 상속받은 a' 에도 접근이 가능하긴 함
    // -> 어느 클래스에 속한 멤버인지를 명시해주면 됨 (이름 공간 명시와 비슷한 형태로 작성)
    */

    Derived d;

    d.Print();          // From Derived!!! -> Derived 클래스에 있는 메서드가 우선적으로 호출됨
    d.Base::Print();    // From Base!!!
    d.Derived::Print(); // From Derived!!!
}
