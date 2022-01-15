// 객체에 대한 동적 할당

#include <iostream>

using namespace std;

class Vector2 {
public:
    Vector2()
        : x(0)
        , y(0)
    {
        cout << this << " : Vector2()" << endl; // 객체의 주소와 호출된 메서드를 출력
    }
    Vector2(const float x, const float y)
        : x(x)
        , y(y)
    {
        cout << this << " : Vector2(const float x, const float y)" << endl;
    }

    ~Vector2()
    {
        cout << this << " : ~Vector2()" << endl;
    }

    float GetX() const { return x; }
    float GetY() const { return y; }

private:
    float x;
    float y;
};

int main()
{
    Vector2 s1;       // == Vector2 s1 = Vector2();
    Vector2 s2(3, 2); // == Vector2 s2 = Vector2(3, 2);

    // s1, s2 는 정적(static), d1, d2 은 동적(dynamic)
    Vector2* d1 = new Vector2();
    Vector2* d2 = new Vector2(3, 2);

    // (*d1).GetX() == d1->GetX() => 구조체에 적용되는 문법을 클래스에도 똑같이 적용할 수 있음
    cout << "(" << d1->GetX() << ", " << d1->GetY() << ")" << endl;
    cout << "(" << d2->GetX() << ", " << d2->GetY() << ")" << endl;

    delete d1;
    delete d2;
    // 생성은 s1, s2, d1, d2 순서, 소멸은 d1, d2, s1, s2 순서
    // 동적 할당된 객체의 경우, 객체가 소멸하면서 할당된 공간이 해제됨
}
