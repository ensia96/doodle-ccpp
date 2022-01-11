// namespace 중첩 : 이름 공간 안에 또 다른 이름 공간 정의하기

#include <iostream>

using namespace std;

int n;
void set()
{
    n = 10;
}

/*
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
    ::set();
    doodle::set();
    doodle::google::set();

    cout << ::n << endl;
    cout << doodle::n << endl;
    cout << doodle::google::n << endl;
}
*/

/*
namespace doodle {
int n;
void set()
{
    n = 20;
}

namespace google {
    void set()
    {
        n = 30; // n이 없으므로, 한 단계 밖으로 나감 -> doodle::n
    }
    int n;
}
}

int main()
{
    ::set();
    doodle::set();
    doodle::google::set();

    cout << ::n << endl;
    cout << doodle::n << endl;
    cout << doodle::google::n << endl;
}
*/

/*
namespace doodle {
void set()
{
    n = 20;
}

namespace google {
    void set()
    {
        n = 30; // 이번에는 doodle 에도 n이 없으므로, 다시 한 단계 밖으로 나감 -> ::n
    }
    int n;
}
int n;
}

int main()
{
    ::set();
    doodle::set();
    doodle::google::set();

    cout << ::n << endl;
    cout << doodle::n << endl;
    cout << doodle::google::n << endl;
}
*/

namespace doodle {
void set();

namespace google {
    void set();
    int n;
}
int n;
}

int main()
{
    ::set();
    doodle::set();
    doodle::google::set();

    cout << ::n << endl;
    cout << doodle::n << endl;
    cout << doodle::google::n << endl;
}

// 이미 위에서 이름 공간에 n이 정의되었기 때문에, 같은 이름 공간 안에 있는 n을 가리키게 됨
void doodle::set()
{
    n = 20;
}

void doodle::google::set()
{
    n = 30;
}

// 어떤 대상(변수, 함수) 이 어느 범위(이름 공간 등) 내에 있는지 검사하는 작업을 '식별자 검색' 이라고 함
// 컴파일러는 항상 식별자 검색을 수행함 -> 선언 위치를 가장 우선시함 (먼저 선언이 되었는지 아닌지)
