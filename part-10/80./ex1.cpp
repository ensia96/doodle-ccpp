// 이번 시간에는 순수 가상 함수와 추상 클래스에 대해서 배워볼 것임
// 지난 시간까지는 가상함수에 대해서 살펴봤음 (78 ~ 79강)

#include <iostream>

using namespace std;

/*
class A {
public:
    // virtual void f() { cout << "A::f()" << endl; }
    //  A*a = new A; a->f(); => A::f()
    //  -> 존재하지 않는 가상의 함수가 아님
    //  -> 완벽한 가상 함수라고 할 수 없음
    virtual void f() = 0; // NULL 로 선언해도 된다고 함(내 환경에서는 오류 뜸)
};

class B : public A {
public:
    void f()
    {
        cout << "B::f()" << endl;
    }
};

int main()
{
    A* a = new B;
    // A* a = new A;
    // A::f() 를 순수 가상 함수로 바꾸면, A::f() 에 접근할 수 없다는 오류가 뜨게 됨
    // -> 정의되어 있지 않은 함수에는 접근할 수 없기 때문에 오류가 나는 것임
    // -> A처럼 순수 가상 함수를 하나라도 포함하는 클래스를 추상 클래스라고 부름
    // -> 추상 클래스의 가장 큰 특징은 인스턴스(객체) 를 만들 수 없다는 것임
    // -> 추상적으로만 존재하는 클래스이기 때문에, 구체화한 대상(객체) 을 만들 수 없음
    // -> 추상 클래스만으로는 아무것도 할 수 없기 때문에, 클래스 자체에는 큰 의미가 없음
    // -> 대신, 추상 클래스를 상속받아, 멤버들을 오버라이딩해서 사용할 수 있음
    a->f(); // f() 는 가상 함수이므로 동적 바인딩이 일어남
    delete a;
}
*/

const double PI = 3.1415926535897932;

/*
class Circle { // 원
public:
    Circle(double r)
        : r(r)
    {
    }

    double GetArea() // 도형의 너비 반환
    {
        return PI * r * r;
    }

    void Resize(double f) // 주어진 배율만큼 도형을 확대
    {
        r *= f;
    }

private:
    double r; // 원의 반지름
};

class Rectangle { // 직사각형
public:
    Rectangle(double a, double b)
        : a(a)
        , b(b)
    {
    }

    double GetArea()
    {
        return a * b;
    }

    void Resize(double f)
    {
        a *= f;
        b *= f;
    }

private:
    double a, b; // 가로, 세로 길이
};
*/

// 도형(Shape) 클래스를 만들어, 두 클래스가 공통으로 포함하는 요소를 상속하도록 구성을 바꿀 수 있음

class Shape {
public:
    /*
    virtual double GetArea()
    {
        return 0; // 어떤 값을 반환할지가 애매하니, 그냥 0을 반환하도록 해도 됨
                  // -> 직사각형, 원처럼 구체적인 대상도 아니고, 그냥 도형 자체에 대한 객체를 만드는 것은 뭔가 이상함
                  // -> 하지만, Shape::GetArea() 함수가 절대로 호출되지 않는다는 보장은 없음
    }

    virtual void Resize(double f) { }
    */

    virtual double GetArea() = 0;

    virtual void Resize(double f) = 0;
    // 이렇게 순수 가상 함수를 선언하면, 함수를 제대로 사용할 수도 없고, 객체를 만들 수도 없게 됨
    // -> 하지만, 사용하지 않을 함수를 불필요하게 구현할 필요 또한 없어짐
    // -> 추상 클래스를 '클래스의 틀' 로써 생각할 수 있음
    // -> 파생 클래스에서 무조건 구현해야 하는 메서드를 미리 정해주는 느낌 (도형이라면 이런 기능이 있어야 한다.)
    // -> 파생 클래스는 추상 클래스에서 제공한 틀에 맞춰 구현 (오버라이딩)
    // -> 가상 함수를 통해 여러 파생 클래스를 일관되게 처리할 수 있음 (+ 각 클래스에 특화된 동작이 수행됨)
};

// 이렇게 구체적인 대상을 나타내는 클래스들에 대해 공통 부모가 되는 클래스를 만들 수 있음
// -> 부모가 되는 클래스를 따로 사용할 일은 없기 때문에, 순수 가상 함수를 선언해 추상 클래스로 만들어 줄 수 있음

// 이렇게, 순수 가상 함수를 통해 틀을 제공하면(추상 클래스를 구현하면),
// - 함수를 따로 구현하지 않고도, 동적 바인딩으로 얻을 수 있는 이점을 모두 챙길 수 있음
// - 서로 다른 파생 클래스에서 생성된 객체들이 있을 때, 같은 작업을 일관되게 수행시킬 수 있음
// - 파생 클래스마다 특화된 동작을 수행하게 됨

class Circle : public Shape {
public:
    Circle(double r)
        : r(r)
    {
    }

    double GetArea()
    {
        return PI * r * r;
    }

    void Resize(double f)
    {
        r *= f;
    }

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

    double GetArea()
    {
        return a * b;
    }

    void Resize(double f)
    {
        a *= f;
        b *= f;
    }

private:
    double a, b;
};

int main()
{
    Shape* shapes[] = {
        new Circle(10),
        new Rectangle(20, 30)
        // new Shape // <- 추상 클래스이기 때문에 객체 생성 불가

    };

    for (Shape* s : shapes) {
        s->Resize(2);
    }
    for (Shape* s : shapes) {
        cout << s->GetArea() << endl;
    }
    for (Shape* s : shapes) {
        delete s;
    }
}
