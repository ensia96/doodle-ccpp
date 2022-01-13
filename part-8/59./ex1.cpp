// 정적 멤버 변수

#include <iostream>

using namespace std;

/*
// 생성된 객체의 개수를 확인할 방법이 없으므로, 전역 변수 활용
// -> 새로 생성될 객체의 id 를 기록하는 용도
int idCounter = 1;

// 전역 변수지만 Color 클래스와 아주 밀접한 관련이 있음
// -> Color 클래스에 집어넣을 수 있음
// -> 정적 멤버 메서드 때와 마찬가지로, static 키워드를 활용해 정적 멤버 변수로 추가할 수 있음

class Color {
public:
    Color()
        : r(0)
        , g(0)
        , b(0)
        , id(idCounter++)
    // 이 코드도, 다른 코드들과 마찬가지로, 초기화 목록으로 바꿀 수 있음
    {
        // 객체가 생성될 때, 적절한 id 값을 부여하고, idCounter 값을 증가시켜야 함
        // id = idCounter;
        // idCounter++;

        // id = idCounter++; // 이렇게 후위 증가 연산자를 사용하면, 값이 대입된 후에 idCounter 의 값이 1 증가함
        // id = ++idCounter; // 이렇게 전위 증가 연산자를 사용하면, idCounter 의 값이 1 증가한 후에 값이 대입됨
    }
    Color(float r, float g, float b)
        : r(r)
        , g(g)
        , b(b)
        , id(idCounter++) // 오버로딩된 함수에도 똑같이 적용해줘야 함
    {
    }

    float GetR() { return r; }
    float GetG() { return g; }
    float GetB() { return b; }

    int GetId() { return id; } // 멤버 변수가 추가되었으므로, get 함수도 추가해줘야 함

    static Color MixColors(Color a, Color b)
    {
        return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
    }
    // 정적 멤버 변수는 정적 멤버 메서드와 마찬가지로, 특정 객체에 포함되지 않고, 클래스에 포함됨
    // -> 객체를 여러 개 생성해도, 정적 멤버 변수는 하나만 생성됨 (클래스에만 종속되기 때문)

    // 전역 함수를 정적 멤버 메서드로 바꾸면 여러 이점이 생김

private:
    float r;
    float g;
    float b;

    // 객체가 생성될 때마다, 객체마다 번호를 부여하려는 상황이라고 가정 -> blue = 1, red = 2, purple = 3
    // 객체가 생성될 때마다 id 가 1씩 증가해야함
    // -> 위에 선언한 전역 변수인 idCounter 를 활용 -> id = idCounter; idCounter++;
    int id;
};
*/

class Color {
public:
    Color()
        : r(0)
        , g(0)
        , b(0)
        , id(idCounter++)
    {
    }
    Color(float r, float g, float b)
        : r(r)
        , g(g)
        , b(b)
        , id(idCounter++)
    {
    }

    float GetR() { return r; }
    float GetG() { return g; }
    float GetB() { return b; }

    int GetId() { return id; }

    static Color MixColors(Color a, Color b)
    {
        return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
    }

    static int idCounter; // 정적으로 선언된 변수는 클래스 안에서 초기값을 줄 수 없음
                          // -> 클래스 안에서는 값을 대입해줄 수 없음
                          // -> 멤버 변수에 값을 대입하는 문법은 비교적 최근에 생김
                          // -> 원래는 생성자 안에서 값을 지정해줘야 했음
                          // -> 편의성을 위해 추가됨
                          // -> 멤버 변수에 값 대입 == 생성자에서 값 지정
                          // -> 정적 멤버 변수가 생성자 함수 안에 들어가는 상황이 넌센스하다는 것이 문제
                          // -> 왜냐하면, 정적 멤버는 객체에 포함되는 것이 아닌, 클래스에 종속되는 요소이기 때문
                          // -> 또, 객체가 생성될 때마다 정적 멤버 변수에 값을 대입한다는 것도 말이 안 됨
                          // -> 따라서, 초기값은 클래스 외부에서 지정해줘야 함
                          // -> 이 때, 정적 멤버에 대해서는 클래스 이름이 이름 공간과 비슷한 역할을 함 (Color::MixColors)

    // MixColors, idCounter 는 원래 전역에 선언된 함수, 변수였음
    // -> Color 클래스와 밀접한 관련이 있어서 클래스에 집어넣음
    // -> 정적 멤버 메서드의 경우, private 영역에 있는 멤버 변수에 접근할 수 있다는 것이 장점이었음

    // 사실, 가장 큰 장점은, 전역 변수로 사용했을 때 생길 수 있는 혼잡성을 줄일 수 있다는 것임
    // -> 규모가 큰 프로그램의 경우, 클래스가 여러 개 있을 수 있음
    // -> idCounter 를 사용하는 클래스 또한 여러 개 있을 수 있음
    // -> 그랬다면, 이름 중복을 방지하기 위해 colorIdCounter, 000IdCounter, ... 등의 작업이 필요했을 것임
    // -> 이렇게, 전역 변수를 여러 개 선언하면, 프로그램이 난잡해질 가능성이 큼
    // -> 프로그램이 커질수록 필요한 전역 변수가 더 늘어날 것이기 때문
    // -> 이러한 이유로, 객체 지향 프로그래밍에서는 전역 변수 사용을 지양하는 것이 바람직함
    // -> C# 의 경우, 전역 변수라는 개념 자체가 문법에 포함되지 않음 -> 모든 변수/함수는 클래스 안에만
    // -> C++ 의 경우, 기존에 사용되던 C 언어와의 호환성을 위해 전역 변수/함수 관련 문법을 지원하는 것
    // -> C# 처럼 전역 변수/함수의 존재 자체를 없앨 정도는 아니긴 함
    // -> 그렇지만, 전역 변수/함수를 남용한 만큼 프로그램이 난잡해질 수밖에 없다는 것은 변하지 않음

    // 결론)
    // 되도록이면, 클래스와 관련된 변수/함수들은 정적으로 선언해서, 클래스로 집어넣는 것이 좋음
    // 전역 변수/함수는 만들지 않을수록 좋음

private:
    float r;
    float g;
    float b;

    int id;
};

int Color::idCounter = 1; // 이런 식으로 적어줘야 함
                          // 이름 공간에서 선언과 정의를 분리시킬 때 썼던 방법

int main()
{
    Color blue(0, 0, 1);
    Color red(1, 0, 0);

    Color purple = Color::MixColors(blue, red);

    cout << "r = " << purple.GetR() << ", g = " << purple.GetG() << ", b = " << purple.GetB() << endl;

    cout << "blue.GetId = " << blue.GetId() << endl;     // 1
    cout << "red.GetId = " << red.GetId() << endl;       // 2
    cout << "purple.GetId = " << purple.GetId() << endl; // 3
}
