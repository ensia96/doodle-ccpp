// static : 정적 (멈춰있다) <-> 동적 (움직인다)

// 클래스의 멤버 변수 또는 메서드의 종류는 두 가지로 나뉨 -> 정적일 수도 있고, 동적일 수도 있음
// 이전까지의 수업에서 살펴봤던 멤버들은 모두 동적 멤버에 해당함

// 동적이다. -> 쉽게 말하면, 객체에 포함된다. -> 객체마다 따로 저장됨
// 정적이다. -> 클래스마다 하나씩만 저장됨

#include <iostream>

using namespace std;

// (0 ~ 1) float R G B <- char 형으로 저장해도 되지만, 계산의 편의를 위해 float 형 사용

/*
class Color {
public:
    Color()
        : r(0)
        , g(0)
        , b(0)
    {
    }
    Color(float r, float g, float b)
        : r(r)
        , g(g)
        , b(b)
    {
    }

    float GetR() { return r; }
    float GetG() { return g; }
    float GetB() { return b; }

private:
    float r;
    float g;
    float b;
};

Color MixColors(Color a, Color b) // 이 함수는 Color 클래스와 밀접한 관련이 있음 -> Color 객체에 집어 넣는 것이 더 적합할 것임
{
    // Color res((a.GetR() + b.GetR()) / 2, (a.GetG(), b.GetG()) / 2, (a.GetB() + b.GetB()) / 2);
    // -> 강의 영상에서의 오타 (동작은 함) -> 이렇게 작성하면 a.GetG() 의 값은 무시되고, b.GetG() 의 값만 처리됨

    // Color res((a.GetR() + b.GetR()) / 2, (a.GetG() + b.GetG()) / 2, (a.GetB() + b.GetB()) / 2); // 두 색이 갖는 RGB 값이 평균이 저장됨
    // return res;

    return Color((a.GetR() + b.GetR()) / 2, (a.GetG() + b.GetG()) / 2, (a.GetB() + b.GetB()) / 2);
    // int a = 5; return a; -> return 5; 와 같은 원리
}

int main()
{
    Color blue(0, 0, 1);
    Color red(1, 0, 0);

    Color purple = MixColors(blue, red);

    cout << "r = " << purple.GetR() << "g = " << purple.GetG() << "b = " << purple.GetB() << endl;
}
*/

class Color {
public:
    Color()
        : r(0)
        , g(0)
        , b(0)
    {
    }
    Color(float r, float g, float b)
        : r(r)
        , g(g)
        , b(b)
    {
    }

    float GetR() { return r; }
    float GetG() { return g; }
    float GetB() { return b; }

    // Color MixColors(Color a, Color b)
    // 이렇게 무작정 집어넣으면 안됨
    // -> 외부에서 사용하려면, 어떤 객체에 소속되어 있는지를 명시해야 함
    static Color MixColors(Color a, Color b) // 함수의 반환 타입 앞에 static 키워드를 추가해주면 정적인 메서드가 됨
    {
        // return Color((a.GetR() + b.GetR()) / 2, (a.GetG() + b.GetG()) / 2, (a.GetB() + b.GetB()) / 2);
        return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
        // 클래스 내부에 포함되어 있기 때문에, 이렇게 내부에 있는 private 영역에도 접근할 수 있음 -> 편함
    }
    // 전역 함수가 어떤 클래스와 밀접한 관련이 있고, private 영역에 있는 멤버에 접근해야 하는 경우, 전역 함수를 정적 메서드로 바꿔주면 됨

private:
    float r;
    float g;
    float b;
};

int main()
{
    Color blue(0, 0, 1);
    Color red(1, 0, 0);

    // Color purple = MixColors(blue, red);
    // 소속을 명시해줘야함
    // red.MixColors, blue.MixColors, purple.MixColors 는 좀 어색함 -> 되기는 함
    // -> 이런 상황에서 쓸 수 있는 것이 static
    // -> 정적 메서드로 선언을 해둬도, 특정 객체에 포함된 메서드처럼 사용할 수 있음 => red.MixColors 처럼
    // -> 동적 멤버보다 표현하기 더 편함

    Color purple = Color::MixColors(blue, red); // 정적 메서드는 이렇게 사용 (이름 공간의 함수를 사용하듯)
                                                // -> 결과는 같지만, 코드가 좀 더 직관적으로 변함

    cout << "r = " << purple.GetR() << ", g = " << purple.GetG() << ", b = " << purple.GetB() << endl;
}
