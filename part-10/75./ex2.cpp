// 접근 제어
// public, protected, private <- 접근 제어 지시자

// public    : 외부 접근 o 자식 클래스 o
// protected : 외부 접근 x 자식 클래스 o
// private   : 외부 접근 x 자식 클래스 x

// protected 와 private 의 차이는, 자식 클래스에서의 접근 가능 여부에서 생김

// 상속이 일어날 때, 모든 멤버를 상속받지만, private 멤버에는 접근 불가 (사실상 상속 x)

#include <iostream>

using namespace std;

class Base {
public:
    int bPublic;

protected:
    int bProtected;

private:
    int bPrivate;
};

// 1. 자식 클래스에서 접근 가능한 멤버는?
// 2. 외부에서 접근 가능한 멤버는?

class Derived : public Base { // public 수준으로 상속받겠다는 뜻
                              // -> (공개 수준) (부모 클래스 이름) 형태로 작성함
                              // -> 공개 수준은 대부분 public (거의 99%)
                              // -> 선언된 공개 수준보다 더 공개되어 있는 멤버들을 선언된 공개 수준으로 바꿈
                              // -> protected 수준으로 상속받으면, 접근 제한 수준이 protected 이상으로 지정됨
                              // -> 부모의 public 멤버는 protected, protected 멤버도 protected 로 바뀜
                              // -> private 수준으로 상속받으면, 모든 멤버가 private 이 됨
                              // -> 부모 클래스 B의 파생 클래스 D의 파생 클래스 DD에서는 D의 멤버에 접근 불가(전부 private)
public:
    int dPublic;

    void DFunc()
    {
        bPublic = 1;
        bProtected = 2;
        // bPrivate = 3;
        dPublic = 4;
        dPrivate = 5;
    }

    // protected 멤버는 따로 선언 x (지금 예제에서는 필요 x)

private:
    int dPrivate;
};

int main()
{
    Base b;
    Derived d;

    b.bPublic = 1;
    // b.bProtected = 2;
    // b.bPrivate = 3;

    d.bPublic = 1; // 부모에게 상속받은 public 멤버는 자식에서도 public 멤버로 취급됨
    // d.bProtected = 2;
    // d.bPrivate = 3;
    d.dPublic = 4;
    // d.dPrivate = 5;

    // DFunc, main 함수에서 접근할 수 없는 멤버들은 주석 처리
}
