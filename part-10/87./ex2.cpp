#include <iostream>
#include <math.h> // 소스 코드에 이게 없었음;
#include <string>
using namespace std;

const double PI = 3.141592653589793;

class Shape {
public:
    virtual ~Shape() { }
    virtual double GetArea() const = 0;
    virtual void Resize(double factor) = 0;
    virtual string GetInfo() const // 순수 가상 함수로 선언해도 되긴 함
    {
        return "도형의 넓이 : " + to_string(GetArea());
    };
};

class Circle : public Shape {
public:
    Circle(double r)
        : r(r)
    {
    }

    double GetArea() const
    {
        return r * r * PI;
    }
    void Resize(double factor)
    {
        r *= factor;
    }

    // Circle 클래스에서는 따로 GetInfo() 메서드를 오버라이딩해줄 필요가 없음

private:
    double r;
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
    void Resize(double factor)
    {
        a *= factor;
        b *= factor;
    }

    double GetDiag() const
    {
        return sqrt(a * a + b * b);
    }

    // Rectangle 클래스에서는 대각선의 길이도 반환해야 하므로 오버라이딩 필요
    string GetInfo() const
    {
        return Shape::GetInfo() + "\n대각선의 길이 : " + to_string(GetDiag());
    }

private:
    double a, b;
};

int main()
{
    Shape* shapes[] = { new Circle(1), new Rectangle(1, 2) };

    // dynamic_cast 를 사용하지 않고, 아래와 똑같이 동작하는 코드 작성하기
    /*
    for (Shape* s : shapes) {
        cout << "도형의 넓이 : " << s->GetArea() << endl;
        Rectangle* r = dynamic_cast<Rectangle*>(s);
        if (r != NULL) {
            cout << "대각선의 길이 : " << r->GetDiag() << endl;
        }
    }
    // 방법 모르겠음;
    */
    for (Shape* s : shapes) {
        // s->PrintInfo(); <- 이런 식으로, 새로운 함수를 만들면 됨 (?????????????????)
        // -> 직접 출력하는 함수보다, 문자열 정보를 출력하는 함수가 더 활용도가 높음
        // -> 도형 정보를 다른 식으로 활용할 수도 있음 (다른 파일에 저장하는 등)
        // -> PrintInfo() 보다는 GetInfo() 를 만드는 것이 더 나음
        cout << s->GetInfo() << endl;
    }

    // 기존 코드의 경우, 포인터 s가 가리키고 있는 대상의 자료형을 직접 알아내야 했음
    // -> 바뀐 코드의 경우, 자료형에 관계 없이 메서드 하나로 모두 해결됨
    // -> 이것이 추상 클래스를 사용하는 이유, 추상화를 사용하는 목적임
    // -> 사용자가 정보를 직접 확인하느냐, 클래스 개발자가 그런 인터페이스까지 제공하느냐의 차이

    for (Shape* s : shapes) {
        delete s;
    }
}
