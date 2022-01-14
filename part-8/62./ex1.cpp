// 연산자 오버로딩

#include <iostream>

using namespace std;

class Vector2 {
public:
    Vector2();
    Vector2(float x, float y);

    float GetX() const;
    float GetY() const;

    /*
    static Vector2 Sum(Vector2 a, Vector2 b)
    {
        return Vector2(a.x + b.x, a.y + b.y);
    }
    */

    /*
    // Vector2 Add(Vector2 rhs)
    Vector2 operator+(Vector2 rhs) // operator 는 예약어여서 다른 이름으로 대체 불가
                                   // 다른 멤버 메서드처럼도 사용 가능
                                   // 객체에 대해 연산자를 사용할 수 있게 됨
    {
        return Vector2(x + rhs.x, y + rhs.y);
    }
    */
    // 이 메서드에는 크게 3가지 결함이 있음
    // -> 혼자만 선언, 정의가 분리되어 있지 않음
    // -> 상수형 메서드로 선언할 수 있음에도, 그냥 선언되어 있음
    // -> 매개 변수도 상수화할 수 있지만, 그냥 정의되어 있음
    Vector2 operator+(const Vector2 rhs) const;
    // 이렇게 더하기 연산에 대해 정의를 했으면, 다른 연산들도 정의할 수 있을 것임
    // -> 지난 수업에서 간단하게 살펴봤던 벡터에 대한 사칙연산을 모두 구현해볼 것임
    Vector2 operator-(const Vector2 rhs) const;
    Vector2 operator*(const float rhs) const;
    Vector2 operator/(const float rhs) const; // a / 2 = a * (1 / 2) -> 벡터를 실수로 나눌 수 있음, 벡터로 나눌 수는 없음
    float operator*(const Vector2 rhs) const;

    // 이러한 사칙 연산 외에, 대입 연산자나 형 변환 등 다른 연산자에 대해서도 연산자 오버로딩이 가능함
    // (형 변환도 일종의 연산자라고 볼 수 있음)
    // -> 나머지 다른 연산자들에 대한 연산자 오버로딩은 책이나 인터넷 검색 등을 통해 직접 알아볼 것

private:
    float x;
    float y;
};

/*
Vector2 Sum(Vector2 a, Vector2 b) // 정적 메서드를 다시 전역 함수로
{
    return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY());
}
*/
Vector2 operator*(const float a, const Vector2 b) // 매개 변수를 2개 받는 operator 함수 -> 각각 좌변, 우변
                                                  // 클래스 내부에 선언된 연산자 오버로딩용 메서드는 멤버 연산자라고 부름
                                                  // 전역에 선언된 연산자 오버로딩용 함수를 비멤버 연산자라고 부름
                                                  // (둘 다 공식 명칭은 아님)
                                                  // 멤버 연산자의 경우, 객체(자기 자신) 를 좌변, 매개 변수를 우변으로 취급함
                                                  // 비멤버 연산자의 경우, 전역이므로, 좌변과 우변을 모두 매개 변수로 받음
{
    return Vector2(a * b.GetX(), a * b.GetY());
}

int main()
{
    /*
    Vector2 a(2, 3);
    Vector2 b(-1, 4);
    // Vector2 c1 = Vector2::Sum(a, b);
    Vector2 c1 = Sum(a, b);
    // Vector2 c2 = a.Add(b);
    Vector2 c2 = a.operator+(b);
    Vector2 c3 = a + b; // operator+ 메서드가 정의되어 있으면, 이렇게 적어도 정상적으로 동작함
                        // + 연산자를 사용하면 자동으로 operator+ 메서드가 호출됨
                        // 이 코드에서 + 는 연산자이지만, 메서드와 비슷한 역할을 함
                        // 연산자를 다른 메서드보다 더 편하게 사용할 수 있는 메서드라고 볼 수도 있음
    */
    Vector2 a(2, 3);
    Vector2 b(-1, 4);
    Vector2 c1 = a - b;
    // Vector2 c2 = a * 1.6;
    Vector2 c2 = 1.6 * a; // 이렇게 실수에 벡터를 곱하면 오류가 뜸
                          // a * 1.6 == a.operator*(1.6)
                          // 1.6 * a != (1.6f).operator(a);
                          // float 과 같은 C 언어의 기본 자료형들은 객체가 아니기 때문에 연산자 오버로딩이 불가능함
                          // -> 위에 정의된 Sum 과 비슷한, 전역 함수의 형태로 연산자를 오버로딩하면 됨
    // Vector2 c3 = a / 2;
    Vector2 c3 = 1.6 * a; // 전역에 선언된 비멤버 연산자이기 때문에, (1.6).operator(a) 형태로는 적을 수 없음
    float c4 = a * b;

    cout << a.GetX() << ", " << a.GetY() << endl;
    cout << b.GetX() << ", " << b.GetY() << endl;
    cout << c1.GetX() << ", " << c1.GetY() << endl;
    cout << c2.GetX() << ", " << c2.GetY() << endl;
    cout << c3.GetX() << ", " << c3.GetY() << endl;
    cout << c4 << endl;
}

Vector2::Vector2()
    : x(0)
    , y(0)
{
}
Vector2::Vector2(float x, float y)
    : x(x)
    , y(y)
{
}

float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }

Vector2 Vector2::operator+(const Vector2 rhs) const
{
    return Vector2(x + rhs.x, y + rhs.y);
}
Vector2 Vector2::operator-(const Vector2 rhs) const
{
    return Vector2(x - rhs.x, y - rhs.y);
}
Vector2 Vector2::operator*(const float rhs) const
{
    return Vector2(x * rhs, y * rhs);
}
Vector2 Vector2::operator/(const float rhs) const
{
    return Vector2(x / rhs, y / rhs);
}
float Vector2::operator*(const Vector2 rhs) const
{
    return x * rhs.x + y * rhs.y;
}
