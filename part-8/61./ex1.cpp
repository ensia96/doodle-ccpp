// 연산자 오버로딩
// -> 예제에서 벡터를 사용해야 함
// -> 멤버 메서드에 대해서도 알아야 함
// => 일단은 벡터와 멤버 메서드부터

// 벡터 : 수학에서는 꽤 유명한 개념, 여러 개의 실수들이 묶여있는 형태
// 벡터끼리도 실수처럼 연산을 할 수 있음
// -> 덧셈, 뺄셈, 곱셈, 나눗셈 등등
// -> 실수에 벡터를 곱할 수도 있음 (벡터의 각 성분에 실수의 값을 곱하면 됨)
// -> 벡터끼리 곱하는 경우 = 내적과 외적으로 나뉨 => · == 내적 ,× == 외적 | 내적 = 도트(dot) 곱이라고도 함
// -> 벡터끼리 내적으로 곱한 결과는 실수임
// -> 벡터는 그래픽 요소나 게임을 만드는 경우에 대해서는 아주 기본적인 개념임

// 멤버 메서드의 선언, 정의 분리하기
// -> 멤버 변수의 경우, 정적 멤버 변수를 제외하고는 선언과 정의를 따로 하는 경우가 적음
// -> 반대로, 멤버 메서드는 선언과 정의를 분리하는 것이 일반적임 -> 대부분의 경우(거의 90%)
// -> 함수의 선언, 정의를 분리하는 이유 : 함수 간의 호출 관계가 선언 순서와 어긋나는 상황이 생길 수 있기 때문

// 이름 공간 내부의 함수에 대한 선언, 정의를 분리하는 방식도 살펴봤었음
// -> '클래스 이름을 이름 공간처럼 취급해도 된다' 라고도 했었음 (메서드를 포함하는 클래스는 이름 공간의 역할을 할 수 있음)
// -> '이름 공간 내부의 함수에 대한 선언, 정의 분리 방식' 은 클래스의 멤버 메서드에도 똑같이 적용됨

#include <iostream>

using namespace std;

class Vector2 { // 성분이 2개인 벡터만 취급하는 클래스
public:
    /*
    Vector2()
        : x(0)
        , y(0)
    {
    }
    Vector2(float x, float y)
        : x(x)
        , y(y)
    {
    }
    */
    Vector2();
    Vector2(float x, float y);
    // 생성자도 이런 식으로 선언, 정의를 분리할 수 있음

    // 멤버 변수가 얼마 없는 단순한 객체여서, set 함수를 두지 않는 것이 더 나을 수도 있음
    // 값 하나를 바꾸기 위해 함수를 여러 개 정의하고 매번 함수를 호출하는 것보다는, 새 객체를 만드는 게 더 나을 수도 있기 때문

    /*
    float GetX() const { return x; } // get 함수는 상수 메서드로 선언해주는 것이 좋음
    float GetY() const { return y; }
    */
    float GetX() const;
    float GetY() const;
    // 상수 메서드도 이런 식으로 선언, 정의를 분리할 수 있음

    // 이렇게, 전역 함수를 다시 클래스의 멤버 메서드로 바꿔주면 더 좋음
    // + static 키워드를 이용해 정적 메서드로 지정
    static Vector2 Sum(Vector2 a, Vector2 b)
    {
        // return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY());
        return Vector2(a.x + b.x, a.y + b.y); // 멤버 메서드이므로, get 함수들을 이렇게 대체할 수 있음
    }

    // 임의의 객체 a가 있다고 가정하고, Add 라는 동적 함수를 선언하는 방법도 생각해볼 수 있음
    // -> Add 함수는 다른 Vector2 객체를 입력받은 후, a에 b를 더한 결과를 반환하는 함수임
    // -> Vector2 Add(Vector2 b) { return a + b; } 형태
    Vector2 Add(Vector2 rhs) // rhs = right hand side = 우변 = 연산자보다 우측에 있는 항 <-> 좌변
    {
        return Vector2(x + rhs.x, y + rhs.y);
        // 자기 자신의 x, y 와 입력받은 객체의 x, y 값을 더한 후, 그 값으로 새 객체를 생성해서 반환
        // 정적 메서드와는 다르게 어떤 객체에 포함될 수 있으므로, 다른 연산 대상만 입력받으면 됨
    }
    // 연산자 오버로딩은 이러한 동적 메서드와 밀접한 관련이 있음

private:
    float x;
    float y;
};

/*
// 제일 먼저 생각해 볼 수 있는 방법 새로운 함수를 만드는 것임
Vector2 Sum(Vector2 a, Vector2 b)
{
    return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY()); // 벡터 성분값을 직접 더한 후, 그 값으로 새 객체 생성
}
*/

int main()
{
    Vector2 a(2, 3);
    Vector2 b(-1, 4);
    // Vector2 c = a + b;
    // 이렇게, 벡터에 대한 연산의 결과를 저장해야 하는 상황이 생길 수도 있음
    // -> 계산 방법을 따로 정의하지 않으면, 오류가 뜸
    // -> 컴파일러 입장에서 보면, 클래스 두 개를 더하는 상황
    // -> 연산자 오버로딩이라는 개념을 활용하면, 이러한 연산도 가능해짐
    // -> 연산자 오버로딩은 다음 시간에 배울 예정이므로, 이를 대체할 방법부터 알아볼 것임
    // Vector2 c = Sum(a, b); // 이렇게 대체 가능
    // Vector2 c = Vector2::Sum(a, b); // 정적(static) 메서드 활용
    Vector2 c1 = Vector2::Sum(a, b);
    Vector2 c2 = a.Add(b); // 동적(dynamic) 메서드 활용

    cout << a.GetX() << ", " << a.GetY() << endl;
    cout << b.GetX() << ", " << b.GetY() << endl;
    cout << c1.GetX() << ", " << c1.GetY() << endl;
    cout << c2.GetX() << ", " << c2.GetY() << endl;
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
