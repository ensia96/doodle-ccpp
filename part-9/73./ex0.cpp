#include <iostream>

using namespace std;
// 0. 다음 프로그램의 실행 결과는?

int main()
{
    char str[] = "Hello, World!";

    cout << str << endl;  // Hello, World!
    cout << *str << endl; // Hello, World! -> H

    /*
    // *str == str[0] -> H

    char* p_str = str;

    cout << p_str << endl;
    cout << *p_str << endl;
    // 이렇게 작성했다고 가정하면, 위에서 나왔던 것과 같은 결과가 나와야 함
    // -> p_str == str == &str[0] 이기 때문

    // p_str : 문자열 전체가 출력됨
    // *p_str : 그 주소에 있는 값인 H 가 출력됨

    // 이런 부분을 헷갈리면 안됨
    */
}
