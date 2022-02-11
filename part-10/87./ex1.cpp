#include <iostream>
using namespace std;

class A {
public:
    virtual int f() { return x; } // == return A::x;
    // virtual int g() {}; // 추가
    virtual ~A() { }

private:
    int x = 10;
};

class B : public A {
public:
    int f() { return x; } // == return B::x;
                          // 이렇게 가상 함수를 오버라이딩한 함수도 가상 함수임 <- 이번에 새로 배운 내용..
    virtual int g() { return A::f(); }

private:
    int x = 20;
};

class C : public B {
public:
    int f() { return x; }
    int g() { return B::f(); }
    virtual int h() { return B::g(); }

private:
    int x = 30;
};

int main()
{
    A* a = new B;
    A* b = new C;
    B* c = new C;
    C* d = new C;
    /*
    // 아래 코드 중 오류가 발생하는 코드 찾기 + 출력 결과 예상해보기
    cout << a->f() << endl;
    cout << a->g() << endl;
    cout << b->f() << endl;
    cout << b->g() << endl;
    cout << c->f() << endl;
    cout << c->g() << endl;
    cout << d->g() << endl;
    cout << d->h() << endl;
    */
    /*
    cout << a->f() << endl;
    cout << a->g() << endl; // 오류
    cout << b->f() << endl;
    cout << b->g() << endl; // 오류
    cout << c->f() << endl;
    cout << c->g() << endl;
    cout << d->g() << endl;
    cout << d->h() << endl;
    // 출력 결과 : 20, 10, 30, 20, 20, 20, 20, 10
    */
    cout << a->f() << endl;
    // cout << a->g() << endl; // 오류 -> A 클래스에는 g() 가 없기 때문
    cout << static_cast<B*>(a)->g() << endl; // a는 무조건 B 객체를 가리킴
                                             // -> static_cast 를 써서, 다운캐스팅할 수 있음
                                             // -> dynamic_cast 를 써도 되긴 함
                                             // -> B::g() 가 실행됨
    cout << b->f() << endl;
    // cout << b->g() << endl; // 오류 -> A 클래스에는 g() 가 없기 때문
    if (C* t = dynamic_cast<C*>(b)) { // 새로운 포인터를 선언한 후, dynamic_cast 결과를 할당
                                      // -> dynamic_cast 는 형 변환 결과(주소값) 또는 NULL 을 반환함
                                      // -> NULL == 0 => 매크로
                                      // -> 0을 제외한 모든 값은 참으로 취급됨
                                      // -> 형 변환에 성공했을 때만 if 문 안에 있는 내용이 실행됨
        cout << t->g() << endl;
    }
    cout << c->f() << endl;
    cout << c->g() << endl;
    cout << d->g() << endl;
    cout << d->h() << endl;
    // 출력 결과 : 20, 10, 30, 20, 30, 20, 20, 10

    delete a;
    delete b;
    delete c;
    delete d;
}
