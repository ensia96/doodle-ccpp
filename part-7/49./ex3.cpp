#include <iostream>
#include <string> // 굳이 필요한건 아닌데, 컴파일러에 따라 필요해질 수 있음

using namespace std;

/*
int main()
{
    // char str[] = "Hello, World!"; // C 언어에서의 문자열 선언 방식

    string str; // 배열 형태가 아니라 일반 변수처럼 다룰 수 있음 (C++ 에서 지원하는 문자열의 장점)
                // 길이를 따로 선언해주지 않아도 됨
    str = "Hello";
    // str = "asdfkljashdfljkashdflhdflkasjdfh" // 이렇게 길게 막 적어도 됨
    cout << str << endl;
}
*/

// C 언어에서는 strlen, strcat 등 문자열을 다루기가 복잡하고 귀찮았음
// C++ 에서는 이렇게, 문자열을 C 언어에서 보다 훨씬 더 유연하게 사용할 수 있음

int main()
{
    string name;

    cout << "이름 입력 : ";
    cin >> name;

    string message = "안녕하세요, " + name + " 님."; // 이렇게 문자열을 쉽게 붙일 수 있음
    cout << message << endl;
}
