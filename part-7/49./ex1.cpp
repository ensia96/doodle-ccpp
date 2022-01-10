// C 언어 때와 마찬가지로, C++ 문법으로 'Hello, World!' 출력하기부터 시작

// #include <stdio.h> // C++ 에서도 쓸 수는 있음
#include <iostream> // istream, ostream 으로 구성됨
                    // input, output 에 관한 stream 들이 저장된 파일임

/*
int main()
{
    // name space : 이름 공간
    // std 는 이름 공간임
    // std 는 성, 뒤에 오는 요소는 이름이라고 할 수 있음
    // 변수 이름만 같은 다른 요소들을 구분짓기 위해 사용
    std::cout << "Hello, World!" << std::endl;

    // 여기서 사용된 시프트 연산자는 출력할 자료를 분리해주는 용도로 사용됨
    // printf("%d %d", 10, 20); 에서 처럼, 별개의 자료들이 순서대로 출력됨
    // std::cout << "Hello, World!" << 10 << 'c' << std::endl;

    // endl = end line
    // 줄을 끝내라 -> 줄바꿈 문자
    // std::cout << "Hello, World!" << '\n'; // 이렇게 해도 됨
}
*/

/*
namespace a {
int n;
}

namespace b {
int n;
}

// 이렇게 이름 공간이 서로 다르면, 변수 이름이 같아도 서로 구분됨

int main()
{
    a::n = 10;
    b::n = 10;
    // 이름 공간이 다르기 때문에 별개의 n으로 인식됨

    std::cout << "Hello, World!" << std::endl;
}
*/

using namespace std; // 이렇게 작성해두면 매번 std:: 을 쓰지 않아도 됨
                     // std 라는 이름 공간을 사용하겠다라는 의미
                     // 아래에서 굳이 명시하지 않아도 자동으로 인식함

int main()
{
    cout << "Hello, World!" << endl;
}
