// namespace (이름 공간)
// 변수나 함수의 이름이 같은 경우, 각 변수 및 함수의 구분이 모호해지는 것을 방지할 때 사용
// -> 이름이 같은 사람을 성으로 구분하는 것에 비유 (김지수, 박지수)

#include <iostream>

using namespace std;

int n; // 어떤 이름 공간에도 속하지 않음 -> 전역 변수
/*
void set() // n 의 값을 설정해주는 함수
{
    //::n = 10; // :: 앞에 이름 공간이 없음 -> 명시적 전역 변수 (n = 10; 과 똑같은 표현)
    n = 10;
}
*/
void set();
namespace doodle {
int n;
/*
void set()
{
    // doodle::n = 20;
    n = 20;
}
*/
void set();
}
namespace google {
int n;
/*
void set()
{
    // google::n = 30;
    n = 30;
}
*/
void set();
}

// 이렇게, 특정한 이름 공간 안에서 어떤 변수나 함수의 소속을 밝히지 않은 경우,
// 자신이 속한 이름 공간 안에 있는 변수나 함수를 가리킴

// => 자신이 속한 이름 공간 안에 있는 변수에 대해서는 소속을 따로 밝혀주지 않아도 됨

/*
namespace google {
int n;
void set()
{
    // ::n = 30; // 전역 소속임을 표현 -> 전역 변수 n 을 가리키게 됨
    doodle::n = 30; // doodle 이름 공간의 소속임을 표현
}
}
*/

int main()
{
    ::set();
    doodle::set();
    google::set();

    cout << ::n << endl;
    cout << doodle::n << endl;
    cout << google::n << endl;
}

/*
void set()
{
    n = 10;
}
*/
void ::set() // 소속 밝혀주기
{
    n = 10;
}
/*
namespace doodle { // 이렇게 이름 공간에 대한 정의를 따로 추가할 수 있음
int a;
int b;
void set() // 함수 때와 마찬가지로, 아래에서 다시 정의할 수 있음 (프로토타입 활용)
{
    n = 20;
}
}
*/
void doodle::set()
{
    n = 20;
}
/*
namespace google {
void set()
{
    n = 30;
}
}
*/
void google::set() // 위의 이름 공간에 프로토타입이 정의되어 있다면, 이렇게 선언할 수도 있음
{
    n = 30;
}
