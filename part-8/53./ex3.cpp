#include <iostream>

// using namespace std; // 이렇게 작성하면, std::cout 의 cout 을 전역 변수처럼 쓸 수 있음

int n;
void set()
{
    n = 10;
}

namespace doodle {
int n;
void set()
{
    n = 20;
}

namespace google {
    int n;
    void set()
    {
        n = 30;
    }
}
}

int main()
{
    using namespace std; // 위치를 아무렇게나 지정할 수 있음 -> 이렇게 작성하면, main 함수 안에서만 유효
    using namespace doodle;
    // 이름 공간을 사용할 때, 전역에 있는 대상과 이름이 겹치는 대상의 경우, 이름만으로 사용할 수 없음

    ::set(); // 아래와 마찬가지로, 전역의 set 함수에 대해서도 set() 형태로 사용할 수 없음
    /*
    set(); // 이렇게 작성하면, ::set 과 마찬가지로, doodle::set 도 set 으로 호출할 수 있음
           // -> 가리키는 대상이 모호해짐 -> set() 형태로 사용할 수 없음
    */
    doodle::set();
    // doodle::google::set();
    google::set(); // 생략 가능 -> doodle 이름 공간은 이미 사용 중이고, 전역에도 google 이라는 이름 공간이 없기 때문

    cout << ::n << endl;
    cout << doodle::n << endl;
    cout << doodle::google::n << endl;
}
