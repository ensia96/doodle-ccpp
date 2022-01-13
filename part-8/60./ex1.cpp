// 상수형 매개 변수, 상수형 메서드

/*
// 상수형 변수 : 절대 변하지 않는 수

double PI = 3.14;

PI = 0; // 이렇게 누군가가 실수로 값을 바꿔버리면, 이후 PI 를 사용하는 모든 계산이 이상해져버림

const double PI = 3.14; // 위와 같은 실수를 방지하기 위해, const 를 붙여서 상수형 변수로 바꿈
*/

// 이번에는 const 의 또 다른 쓰임새에 대해서 알아볼 예정

// 1. 매개 변수의 상수화 (모든 함수)
// 2. 메서드의 상수화 (멤버 메서드)

#include <iostream>

using namespace std;

class Account {
public:
    Account()
        : money(0)
    {
    }
    Account(int money)
        : money(money)
    {
    }

    /*
    void Deposit(int d)
    {
        d = money; // 이런 실수를 했다고 가정 (코드가 길어지면 충분히 발생할 수 있는 실수임)
                   // 이렇게, 인자로 들어온 d 는 절대 변하면 안 되는 값인데, 변해버리게 됨
                   // -> 매개 변수를 상수화하면, 이런 상황을 예방할 수 있음
        money += d;
        cout << d << "원을 예금했다!!" << endl;
    }
    */
    void Deposit(const int d) // d 라는 매개 변수도 상수형 변수가 됨
    {
        // d = money;
        money += d;
        cout << d << "원을 예금했다!!" << endl;
    }
    // void Draw(int d)
    void Draw(const int d) // 위와 마찬가지로 매개 변수를 상수화해두면 좋음
    {
        if (money >= d) {
            money -= d;
            cout << d << "원을 인출했다!!" << endl;
        }
    }

    /*
    int ViewMoney() // money 라는 멤버 변수를 반환하는 역할만 하는 함수임
                    // -> 이런 함수에서 클래스 내에 있는 값이 바뀌면 큰 문제로 이어질 수도 있음
    {
        money++; // 이런 실수를 했다고 가정
        return money;
    }
    */
    int ViewMoney() const
    // const int ViewMoney()
    // 함수를 이런 식으로도 선언할 수 있음
    // -> 물론, 이렇게 정의된 함수는 상수형 메서드는 아님
    // -> 함수가 반환하는 자료가 상수형 변수라는 것을 의미함
    // -> 생각해보면, 함수의 반환값은 애초에 상수이고, 반환값 자체를 바꿀 일도 없음
    // -> 애초에 바꿀 수 없고, 문법적으로도 유효하지 않음 => ViewMoney() = 3
    // -> 이렇게 함수 앞에 const 를 붙이는 것에는 거의 의미가 없음
    // -> 물론, 의미가 있을 때도 있고, 특정 상황에서 사용되기도 함 -> 그냥 참고만
    // -> 상수형 메서드 문법을 헷갈리지 않는 것이 중요
    {
        // money++;
        // 평범한 상수에 값을 대입하려 할 때 뜨는 오류 메시지가 뜸
        // -> 값이 바뀌면 안 되는 함수에서 값을 바꾸려 하는 것이므로, 컴파일 에러를 냄
        return money;
    }

private:
    int money;
};

// 이렇게, 매개 변수와 메서드를 상수화하면, 매개 변수나 멤버 변수의 값이 의도치 않게 바뀌는 상황을 예방할 수 있음

int main()
{
    Account doodle(200);

    doodle.Deposit(100);
    doodle.Draw(20);

    cout << doodle.ViewMoney() << endl;
    // cout << doodle.ViewMoney() << endl;
    // money++ 이 있으면, 돈이 복사가 됨 -> 악용 가능 -> 아주 큰 일
    // => 메서드를 상수화하면, 이런 실수를 방지할 수 있음

    // 메서드를 상수화한다 == 어떤 메서드에 대해, 해당 메서드 내에서 자신이 속한 클래스의 멤버를 건드릴 수 없도록 막는다
}
