//

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
        strData = new char[len + 1];                         // null 문자를 고려해 len+1만큼 할당
        cout << "strData 할당 : " << (void*)strData << endl; // strData 가 char 포인터여서, 주소를 출력하려면, 그냥 출력하면 안 됨
                                                             // -> char 포인터는 char 배열로 취급할 수 있음
                                                             // -> 컴파일러는 strData 가 char 형 포인터인지, char 배열(문자열) 인지 모름
                                                             // -> 그냥 strData 을 적으면, 문자열로 인식하게 됨
                                                             // -> 컴파일러는 strData 를 문자열 형태로 출력하려 함
                                                             // -> (void*) 를 붙여서(형 변환), 주소값을 출력하도록 해줘야 함

        // void* 는 자료 크기, 자료형에 상관없이 주소만 저장함
        // -> 자료형에 대한 정보가 없어서 에 새로운 값 대입 불가능
        // -> void* ptr; *ptr = 'a'; <= 안 됨
        strcpy(strData, str); // 깊은 복사
    }
    // 복사 생성자의 대략적인 형태 -> 복사 생성자 오버로딩 -> 얕은 복사 문제 해결
    String(const String& rhs) // String s2(s1); 이므로, 매개 변수로 String 객체를 받아야함
                              // -> String(String rhs) 형태로 작성하면 안 됨
                              // -> String 객체의 정의에 String 이 포함되기 때문
                              // -> 때문에, 매개 변수를 참조 변수 형태로 지정해줘야 함
                              // -> 복사 생성자 외에 다른 생성자나 멤버 메서드에서는 Method(String par) 형태로 작성해도 됨
                              // -> 원본 객체가 바뀌면 안 되므로, 매개 변수를 상수화해줘야 함
    {
        /*
        strData = rhs.strData; // 얕은 복사
        len = rhs.len;         // 깊은 복사
        // 복사 생성자는 위처럼, 생성될 객체의 모든 멤버 변수에 인자로 들어온 객체의 멤버 변수 값을 대입하는 식으로 동작함
        // -> 모든 멤버 변수를 복사하는 형태
        // -> len 의 경우, 포인터가 아니라 int 형 자료이기 때문에 문제될 게 없음
        // -> 서로 다른 객체에 있는 서로 다른 자료이기 때문에 깊은 복사가 일어나게 됨
        // -> 문제는, strData 의 경우 얕은 복사가 일어나게 된다는 것임
        // -> s1.strData, s2.strData 모두 포인터이기 때문
        // -> 할당 해제를 2번 하게 됨 => 오류 발생
        */

        // => 이를 해결하려면, strData 를 새로 할당한 다음, rhs.strData 에 저장된 자료를 복사해줘야 함
        cout << "String(String& rhs) 생성자 호출" << endl;
        strData = new char[rhs.len + 1]; // 인자로 들어온 객체의 크기만큼 동적으로 할당하면 됨
        cout << "strData 할당 : " << (void*)strData << endl;
        strcpy(strData, rhs.strData); // 깊은 복사
        len = rhs.len;                // 깊은 복사
    }

    ~String()
    {
        cout << "~String() 소멸자 호출" << endl;
        delete[] strData;
        cout << "strData 해제됨 : " << (void*)strData << endl;
        strData = NULL; // 할당 해제 후에 포인터를 NULL 상태로 초기화 해줌
                        // -> 해제된 메모리에는 더이상 접근할 수 없음
                        // -> 초기화를 안 해주면, 이미 할당 해제한 공간에 접근하게 됨
                        // -> 이러한 잘못된 접근을 막기 위해, 포인터를 다시 초기화 해주는 것임
                        // -> 완벽한 해결 방안은 아님 (관습적인 구문임)
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
    String s1("안녕");
    // String s2("안녕"); or String s2 = s1;
    String s2(s1); // 복사 생성자

    /*
    // 이렇게 선언을 먼저 하고, 나중에 할당하는 경우도 있음 -> 다음 시간에
    String s3;
    s3 = s1;
    */

    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;
    // 소멸자는 2번 호출되는데, 생성자는 1번만 호출됨 + s2 객체에 대한 'strData 할당' 메시지도 출력되지 않음
    // -> s2 객체에도 공간이 동적 할당되어야 하는데, 할당되지 않음
    // -> s2.strData 를 위한 공간이 따로 할당되지 않았는데도, '안녕' 은 출력됨
    // -> s1.strData 의 주소값이 s2.strData 에 복사되었을 것이라 추정할 수 있음 (얕은 복사)
    // -> s2.strData == s1.strData 일 수도 있다는 것을 유추할 수 있음

    // String s2(s1); 은 클래스에 선언된 생성자가 아닌, '복사 생성자' 라고 하는 새로운 종류의 생성자임
}
