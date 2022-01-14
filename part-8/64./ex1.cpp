#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass()
        : num(cnt++)
        , ch('\0')
    {
    }

    void Check(MyClass* ptr)
    {
        if (ptr + num == this) {
            cout << num << endl;
        }
    }
    static int cnt;

private:
    int num;
    char ch;
};
int MyClass::cnt = 0;

int main()
{
    MyClass obj[5]; // obj 배열의 각 칸에 MyClass 객체가 들어감
                    // -> 배열이 생성됨과 동시에 객체도 생성됨
                    // -> 이 때, 객체는 0번부터 4번까지 순서대로 생성됨

    cout << "Test #1 : " << endl;
    for (int i = 0; i < 5; i++) { // obj 배열의 0번째 인덱스에 있는 객체부터 하나씩 Check 메서드를 실행
        obj[i].Check(obj);        // -> 인자로 obj 가 전달됨
                                  // -> obj == &obj[i]
                                  // -> Check(MyClass *ptr) -> ptr == &obj[i]
                                  // -> ptr + num == &ptr[num] == &obj[num]
                                  // -> this == &obj[i]
                                  // -> (ptr + num == this) 는 항상 성립하게 됨
    }
    // obj 배열의 시작 주소만 출력됨 -> 배열에 있는 모든 객체의 번호가 출력됨
    // &obj -> 0, 1, 2, 3, 4
    cout << "Test #2 : " << endl;
    for (MyClass& i : obj) { // i 는 참조 변수이므로 어떤 객체를 가리킬 수 있음
                             // 위와 마찬가지로, 0 ~ 4번 인덱스에 저장된 객체를 가리키게 됨
                             // i == obj[j] (0 <= j <= 4)
        i.Check(obj);        // 위의 for 문과 마찬가지로 if 문이 항상 성립하게 됨
    }
    // 배열에 있는 모든 객체의 주소가 출력됨 -> 배열에 있는 모든 객체의 번호가 출력됨
    // t = &obj; t, t+5, t+10, t+15, t+20 -> 0, 1, 2, 3, 4
    cout << "cnt = " << MyClass::cnt << endl;
    // 5
    // -> 객체가 생성될 때마다 cnt++ (총 5번) -> 5
}
// 코드도 제대로 안 읽고, 대충 품..

// 갑자기 포인터 관련 예시가 나온 이유 : 포인터는 앞으로 배울 동적 할당에서 제일 중요한 개념이기 때문
// 참조 변수를 두고 포인터를 사용하는 이유 : 참조 변수를 사용하면 문제점이 많음 -> 반드시 포인터를 사용해야 함
