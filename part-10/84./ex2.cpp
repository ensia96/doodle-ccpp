#include <iostream>
#include <math.h>

using namespace std;

class Shape { // 도형을 저장하는 클래스
public:
    // 순수 가상 함수가 두 개 선언되어 있음
    virtual double GetArea() const = 0; // 도형의 넓이를 반환하는 함수
    virtual void Resize(double k) = 0;  // 도형의 크기를 조절하는 함수
};

class Circle : public Shape {
public:
    Circle(double r)
        : r(r)
    {
    }
    double GetArea() const
    {
        return r * r * 3.14;
    }
    void Resize(double k)
    {
        r *= k;
    }

private:
    double r; // 반지름 길이
};

class Rectangle : public Shape {
public:
    Rectangle(double a, double b)
        : a(a)
        , b(b)
    {
    }
    double GetArea() const
    {
        return a * b;
    }
    void Resize(double k)
    {
        a *= k;
        b *= k;
    }
    double GetDiag() const // 대각선의 길이를 반환하는 함수 (새로 추가)
    {
        return sqrt(a * a + b * b); // math.h 헤더 파일에 들어있는 루트를 구해주는 함수임
    }

private:
    double a, b; // 가로 세로 길이
};

int main()
{
    Shape* shapes[] = { new Circle(1), new Rectangle(1, 2) }; // 포인터 배열

    for (int i = 0; i < 2; i++) {
        // 도형의 넓이
        // 만약 직사각형일 경우, 대각선 길이 출력
        // -> 이런 상황이 dynamic_cast 를 사용하기 좋은 상황임
        cout << "도형의 넓이 : " << shapes[i]->GetArea() << endl;
        Rectangle* r = dynamic_cast<Rectangle*>(shapes[i]);
        // 컴파일 시간에는 shapes[i] 가 가리키는 대상을 알 수 없기 때문에, 이렇게 형 변환을 시도해봐야 함
        // -> static_cast 를 사용하면, *shapes[i] 의 자료형에 상관없이 무조건 성공함
        // -> dynamic_cast 를 사용하면 *shapes[i] 가 Rectangle 객체일 때만 성공함
        // -> 다운캐스팅에 성공하면, 정상적으로 주소값을 반환하고, 아니면, NULL을 반환함
        // -> 이것이 static_cast 와 dynamic_cast 의 차이점임
        if (r != NULL) { // r == NULL : dynamic_cast 실패 => *shapes[i] 는 Rectangle 객체가 아님
                         // r != NULL : dynamic_cast 성공 => *shapes[i] 는 Rectangle 객체임
                         // -> *shapes[i] 가 Rectangle 객체일 때만 실행됨
            cout << "대각선의 길이 : " << r->GetDiag() << endl;
        }
        // Shape 는 다형 클래스이기 때문에 RTTI 가능
        // -> 객체 앞 부분에 클래스 정보가 저장된 공간의 위치를 가리키는 포인터가 저장됨
        // -> 이러한 포인터를 통해 객체의 자료형을 알 수 있게 됨
        // -> dynamic_cast
    }

    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }
}

// dynamic_cast 는 RTTI 를 동반하기 때문에 성능 측면에서 봤을 때 좋은 기능은 아님
// -> RTTI 와 관련된 여러 부수적인 작업들이 실행 시간에 처리되기 때문에 프로그램의 성능이 안 좋아질 수 있음
// -> 때문에, 클래스를 설계할 때, dynamic_cast 를 최대한 활용하지 않는 방향으로 설계하는 것이 좋음
// -> 물론, dynamic_cast 를 사용하지 않는 방법도 있긴 하지만, 클래스 설계 자체를 바꿔야 함
// -> 나중에 문제로 출제할 예정
