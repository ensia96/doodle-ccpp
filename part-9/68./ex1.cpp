#include <iostream>

using namespace std;

class String {
public:
    String()
    {
        cout << "String() 생성자 호출" << endl;
        strData = NULL;
        len = 0;
    }
    String(const char* str)
    {
        cout << "String(const char*) 생성자 호출" << endl;
        len = strlen(str);
        strData = new char[len + 1]; // null 문자를 고려해 len+1만큼 할당
        cout << "strData 할당 : " << (void*)strData << endl;
        strcpy(strData, str); // 깊은 복사
    }
    String(const String& rhs)
    {
        cout << "String(String& rhs) 생성자 호출" << endl;
        strData = new char[rhs.len + 1]; // null 문자를 고려해 len+1만큼 할당
        cout << "strData 할당 : " << (void*)strData << endl;
        strcpy(strData, rhs.strData); // 깊은 복사
        len = rhs.len;
    }

    ~String()
    {
        cout << "~String() 소멸자 호출" << endl;
        delete[] strData;
        cout << "strData 해제됨 : " << (void*)strData << endl;
        strData = NULL;
    }

    /*
    // 연산자 자체를 멤버 메서드로 볼 수 있다고 언급한 적 있음
    // -> 반환하는 값이 따로 없으면 void 형 메서드로 선언하면 됨
    // -> 아래에서 살펴봤듯 대입 연산자가 반환하는 자료의 자료형은 연산 대상의 자료형과 같음

    // String operator=(const String rhs) // 이런 식으로 작성하면 비효율적임
                                          // -> s3.operator=(s1); 의 s1 객체와 매개 변수 rhs 의 객체는 서로 다른 객체임
                                          // -> 함수가 호출되면, 매개 변수 rhs 에 s1 객체가 복사됨 (복사 생성자가 호출됨)
                                          // -> 참조 변수로 바꿔주면 됨
    // String operator=(const String& rhs) // 이렇게 작성해주면, rhs 가 s1 객체를 참조하는 형태가 됨 (복사 x)
    String& operator=(const String& rhs) // 이렇게, 함수 반환값을 참조하도록 선언할 수도 있음
                                         // -> 함수가 어떤 값을 반환하면, 임시 객체가 형성됨
                                         // -> 그리고, 대입 연산은 그 임시 객체를 다시 복사하는 식으로 수행됨
                                         // -> 함수 실행 결과를 참조하도록 함으로써, 불필요한 객체 복사를 또 줄일 수 있음
                                         // -> 연산자 오버로딩을 할 때, 특별한 상황이 아닌 이상, 이런 식으로 작성해주는 것이 좋음
    {
        // 깊은 복사가 일어나도록 해야 함
        // -> 복사 생성자와 비슷하게 구현하면 됨
        // -> 단, 기존에 동적 할당된 공간을 사용중일 수도 있으므로, 할당 해제부터 해줘야함
        delete[] strData;                // strData 의 값이 NULL 이면, 아무런 작업도 하지 않음
        strData = new char[rhs.len + 1]; // null 문자를 고려해 len+1만큼 할당
        cout << "strData 할당 : " << (void*)strData << endl;
        strcpy(strData, rhs.strData); // 깊은 복사
        len = rhs.len;

        // return rhs; // 상수형 String 객체를 반환하겠다는 뜻이 되므로, 이렇게 작성하면 안 됨 (-> const_cast 를 활용하는 방법도 있긴 함)
        return *this; // this == 실행 시점 기준, 해당 함수가 소속된 객체의 주소값
                      // *this == 해당 함수가 소속된 객체의 주소에 저장된 자료 == 해당 함수가 소속된 객체
                      // -> 이렇게 작성하면, 등호가 여러 개 중첩된 상황에서도 의도한 데로 동작할 것임
    }
    // 이 코드에도 결함이 있음
    // -> 자기 자신을 자기 자신에게 대입하는 경우가 있음 (String s3.operator=(s3))
    */

    String& operator=(const String& rhs)
    {
        // 자기 자신이 rhs 와 같은지 비교해야 함
        // -> 객체의 값이 아닌, 객체의 주소값을 비교해야 함
        // -> rhs 는 참조 변수이기 때문에, rhs 로 작성하면 객체 자체로 취급됨
        // -> 앞에 & 를 붙여서 주소값을 비교하도록 해줘야 함
        // -> 자기 자신을 자기 자신에 대입하면, 아무일도 안 일어나게 됨
        if (this != &rhs) {
            delete[] strData;                // 기존에 사용 중이던 공간(s3.strData) 할당 해제
            strData = new char[rhs.len + 1]; // 5 + 1 크기의 공간(len('Hello')) 이 다시 동적으로 할당됨
                                             // -> 새로 할당된 공간이라서, 쓰레기 값이 채워져 있을 것임
            cout << "strData 할당 : " << (void*)strData << endl;
            strcpy(strData, rhs.strData); // == strcpy(s3.strData, s3.strData); -> 아무 일도 일어나지 않음
            len = rhs.len;                // s3.len = s3.len; -> 아무 일도 일어나지 않음
        }

        return *this;
        // 결론적으로, 기존에 저장되어 있던 값은 삭제되고, 쓰레기 값이 채워지게 됨
    }

    char* GetStrData() const
    {
        return strData;
    }

    int GetLen() const
    {
        return len;
    }

private:
    char* strData;
    int len;
};

int main()
{
    /*
    // 다른 객체의 값을 그대로 복사해서 새로운 객체를 생성
    // -> 복사 생성자가 호출됨
    // -> 복사 생성자는 원본 객체의 멤버 변수에 저장된 값을 복사한 후, 새 객체의 멤버 변수에 대입하는 역할을 함
    // -> 이 때, 동적 할당된 멤버 변수가 있다면, 얕은 복사가 일어나게 됨
    // -> 지난 시간에는, 얕은 복사로 인해 생길 수 있는 문제를 예방하기 위해 복사 생성자를 오버로딩했었음
    // -> 이번 시간에는, 객체를 미리 생성해둔 후에, 다른 객체의 정보를 복사해오는 경우에 대해서 살펴볼 것임
    String s1("안녕");
    String s2(s1); // 객체를 생성하는 동시에 복사가 일어남 -> 생성자를 그냥 호출하면 됨
    String s3;     // 객체가 생긴 시점에는 매개 변수가 없는 기본 생성자가 호출됨
    s3 = s1;       // 이렇게 객체가 생성된 다음에 따로 대입을 해주는 경우, 복사 생성자가 호출되지 않음
                   // -> 여기서 사용된 대입 연산자는 복사 생성자와 거의 비슷한 역할을 함
                   // -> 마찬가지로 얕은 복사로 인해 문제가 생김
                   // -> 이는, 이전에 배웠던 연산자 오버로딩을 통해 예방할 수 있음
                   // -> 이번에는 대입(=, 등호) 연산자를 오버로딩해볼 것임

    // s3 + s2; // 연산자 오버로딩으로 해결했었음 (연산자를 멤버 함수처럼 취급)
    */

    /*
    String s1("안녕");
    String s2(s1);
    String s3;
    String s4;
    s4 = s3 = s1; // C 언어에서는 이런 표현도 사용 가능

    int a = 5;
    int b;
    int c = b = a; // 이렇게 하면, a의 값인 5가 b와 c에 대입됨
                   // -> 대입 연산자의 연산 우선순위는 반대임 (오른쪽에 있을수록 우선순위가 높음)
                   // -> b = a 구문이 먼저 실행되어, a의 값이 b에 대입됨
                   // -> b = a 구문의 반환값이 없다면, c에는 아무 값도 대입되지 않을 것임
                   // -> 이 때, b = a 구문은 b와 a에 공통으로 들어가 있는 값인 5를 반환함
                   // -> 내부적으로는, c = b = a 구문이 c = 5 형태로 바뀌는 식으로 동작함
                   // 결론) 대입 연산자도 특정 값을 반환함 -> 반환된 자료의 자료형은 연산 대상의 자료형과 같을 것임
    int d = 5 + 3 + 2;
    // 컴퓨터는 5 + 3 을 먼저 계산한 후, 그 결과에 + 2 를 계산함
    // -> 이렇게, 보통은 왼쪽에 있는 연산자의 우선순위가 더 높음
    */

    String s1("안녕");
    String s2(s1);
    // String s3;
    String s3("Hello"); // 기존에 다른 값이 저장되어 있었다고 가정
    // s3.operator=(s1); // == s3 = s1;
    s3.operator=(s3); // 강의 영상에서는 이상한 문자가 출력됨
                      // -> 쓰레기 값이 들어가기 때문
                      // -> 여기서 쓰레기 값이란, 메모리에 있는 임의의 값을 뜻함
                      // -> 자기 자신에게 자기 자신을 대입하는 것은 자주 할 만한 실수는 아님 (문법적으로도 문제 없음)
                      // -> 그래도, 이런 실수에 대해서도 대비해야 함

    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;
    cout << s3.GetStrData() << endl;
}

// 이번 시간에는 연산자 오버로딩까지, 객체 복사 과정에서의 의도치 않은 얕은 복사를 방지하는 방법에 대해 알아봤음
// 다음 시간에는 의도적으로 얕은 복사를 해볼 예정임
