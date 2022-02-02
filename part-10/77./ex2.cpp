// 정적 바인딩 (동적 바인딩도 있음 -> 다음 시간에 알아볼 예정)
// -> 정적 바인딩은 객체 지향 프로그래밍에 어울리지는 않는 편 (방해함)
// -> Java, C# 의 경우, 정적 바인딩이 잘 일어나지 않음
// -> 반대로, C++ 은 정적 바인딩이 일어남
// -> 정적 바인딩이 일어나는 이유와 어떤 부분에서 문제가 되는지에 대해서 알아볼 것임

#include <iostream>

using namespace std;

class Base {
public:
    void Print()
    {
        cout << "From Base!!!" << endl;
    }
};

class Derived : public Base {
public:
    void Print()
    {
        cout << "From Derived!!!" << endl;
    }
};

/*
int a;
char* p;
p = &a; // C 언어에서는 이렇게 적으면 오류가 남
*/

/*
Derived d;
Base* b = &d; // 이렇게도 작성할 수 있음 -> 심지어 에러도 안 뜸 -> ???
              // -> C++ 에서는 부모 클래스 포인터로 자식 객체를 가리킬 수도 있음
*/

/*
// 남자와 총각 예시 -> Base 는 남자 Derived 는 총각
Base b;
Derived d;

// Base* p = &b; // 남자를 가리키는 포인터가 남자를 가리키는 건 당연히 가능 (문제 없음)
Base* p = &d; // 남자를 가리키는 포인터가 남자에 포함되는 총각을 가리키는 것도 논리적으로는 문제가 없음
*/

class Derived2 : public Base {
    // Base 클래스를 상속받는 또 다른 클래스가 있다고 가정
    // -> 이 클래스에는 Print 함수가 정의되어 있지 않음
};

int main()
{
    Base* b = new Derived(); // Derived 객체를 동적 할당한 후, 할당된 공간의 주소를 b 포인터에 저장
    b->Print();              // == (*b).Point();
                             // -> b는 Base 포인터지만, 실제로는 Derived 객체를 가리키고 있음
                             // -> Base::Print 와 Derived::Print 중에 어떤 것이 실행될까?
                             // -> b는 Base 포인터이기 때문에 Base::Print 가 실행됨 (From Base!!! 가 출력됨)
    delete b;
    b = new Derived2();
    b->Print();
    delete b;
    // 이렇게 작성하면, 코드의 일관성이 사라짐 (가독성이 구려짐)
    // -> 또, 컴파일러 입장에서는, b가 가리키고 있는 대상을 매번 확인해야 함 (번거롭고, 비용이 큰 작업임)
    // -> 이 때, b가 선언될 당시에 가리키고 있던 자료형이 바뀔 일은 없음
    // -> 그러니, 가리키고 있는 대상이 바뀌더라도, 선언 당시에 명시된 자료형을 따라가게 하면 됨
    // -> 이렇게, 포인터가 가리키는 대상이 모호할 때, 어떤 자료형을 가리킬지 정하는 것을 바인딩이라고 함

    // 포인터가 가리키는 대상을 컴파일 시간에 정하는 것을 정적 바인딩이라고 함
    // 반대로, 포인터가 가리키는 대상이 실행 시간 중에 바뀌는 것을 동적 바인딩이라고 함

    // C++ 에서는, 따로 처리해주지 않는 이상 무조건 정적 바인딩이 일어남
    // -> 포인터가 가리키는 대상이 모호하니, 선언 당시의 자료형을 참고하도록 강제하는 것임
    // -> 오버라이딩이 된 상태여도 선언 당시에 명시한 자료형을 우선하게 됨
}

// 핵심
// 상속에서 부모를 가리키는 포인터는 부모 뿐만 아니라 자식도 가리킬 수 있음
// -> 때문에, 실행 시간 중에는 포인터가 가리키고 있는 대상이 모호해짐
// -> 일일이 처리하기엔 비용이 크니, 선언 당시에 지정된 자료형을 따르도록 함
// -> 이를 정적 바인딩이라고 하며, C++ 에서는 기본적으로 이러한 정적 바인딩이 일어남

// 정적 바인딩과 동적 바인딩이 상속에서 가장 중요함