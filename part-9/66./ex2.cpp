// 객체에서 동적 할당 -> 객체를 복사하게 됨 -> 의도치 않게 얕은 복사

// 두 객체 A, B에 포인터가 하나씩 있다고 가정
// -> A를 복사해서 B에 덮어씌우는 경우, 포인터 자체가 복사됨
// -> 내부적으로는 B.a = A.a; 가 됨

// char *str = "Hello"; or char str[] = "Hello";
// #include <string>
// 문자열을 다루는 클래스를 직접 만들어볼 것임

#include <iostream>

using namespace std;

class String {
public:
    String() // 정의 없이 선언만 하는 경우, 동적 할당을 하지 않는 것이 좋은 편임
    {
        strData = NULL; // NULL은 0을 매크로로 지정해둔 값임 (NULL == 0)
                        // 포인터가 현재, 아무 것도 가리키고 있지 않다는 것을 나타낼 때 사용함
        len = 0;        // 동적으로 할당될 문자열이 없으므로, 길이는 0으로 초기화
    }
    String(const char* str) // str == const char를 가리키는 포인터 == char 형 배열 == 문자열
    {
        // strData = str; // 이렇게 작성하면 얕은 복사 -> X
        len = strlen(str);           // 동적 할당 전에, 할당할 공간의 크기부터 알아내야 함
        strData = new char[len + 1]; // 아래처럼 문자열을 복사하기 전에 우선 공간부터 할당해야 함
                                     // NULL 문자(\0) 때문에, (필요한 크기) + 1 만큼의 공간을 할당받아야 함
                                     // 저장할 문자열의 크기에 맞춰서 동적으로 할당된 공간의 주소가 strData 에 저장됨
        strcpy(strData, str);        // 깊은 복사를 위해 strcpy 함수 사용
                                     // strcpy 함수는 문자열 헤더 파일(string.h)에 있음
                                     // iostream 파일은 string.h 파일을 가지고 있음 (바로 사용 가능)
                                     // str 에 저장된 내용을 strData 에 복사
    }

    ~String()
    {
        delete[] strData; // 배열에 대한 할당 해제이므로 '[]' 를 꼭 붙여줘야 함
    }

    char* GetStrData() const // 문자열에 대한 포인터인 strData를 반환하므로, 반환형도 char 자료형에 대한 포인터가 됨
    {
        return strData;
    }

    int GetLen() const
    {
        return len;
    }

private:
    char* strData; // 동적 할당된 공간의 주소
    int len;       // 문자열의 길이
};

// -> 이번 강에서는 객체 내부에서의 동적 할당 방법에 대해서 알아봄
// -> 객체에 대한 동적 할당과 관련된 문제에 대해서는 다음 강의에서 살펴볼 것임

int main()
{
    String s;
}
