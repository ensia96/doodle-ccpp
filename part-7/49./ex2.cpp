#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    // 출력 : cout, << (나가는 모양)
    // 입력 : cin, >> (들어오는 모양)
    // 시프트 연산자를 반대로 써줘야 함
    // scanf 와는 다르게 입력받을 자료형을 알아서 처리해줌

    cout << a << " + " << b << " = " << a + b << endl;
}
