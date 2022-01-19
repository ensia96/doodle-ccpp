// 깊은 복사를 위한  복사 생성자와 복사 대입 연산자가 있었듯, 얕은 복사를 위한 이동 생성자와 이동 대입 연산자가 있음
// -> 이동 시맨틱은 이러한 이동 생성자, 이동 대입 연산자를 통해 구현할 수 있음

#include <iostream>

using namespace std;

class String {
public:
    String()
    {
        cout << "String() : " << this << endl;
        strData = NULL;
        len = 0;
    }
    String(const char* str)
    {
        cout << "String(const char*) : " << this << endl;
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }
    String(const String& rhs)
    {
        cout << "String(const String&) : " << this << endl;
        len = rhs.len;
        alloc(len);
        strcpy(strData, rhs.strData);
    }
    // 현재 예시에서는, getName 함수에서 반환된 res 객체가 임시 객체에 복사되어야 함
    // -> 이를 코드로 표현하면, {임시 객체}(res); 형태가 될 것임
    // -> 그런데 res 은 String 객체이므로, l-value 로 취급되어야 함
    // -> C++ 에서는, 함수에서 어떤 객체가 반환되는 동안에, 그 객체를 r-value 로 간주함 (약간 예외적인 경우)
    // -> 때문에, 임시 객체가 생성되는 시점에는, res 객체가 r-value 로 취급되므로, 이동 생성자가 호출됨

    // 이러한 이동 생성자가 선언되어 있지 않다면, 복사 생성자가 대신 호출됨
    // -> const String& rhs == (값을 바꿀 수 없도록 설정된 String 객체에 대한 참조)
    // -> r-value 또한 값을 바꿀 수 없는 자료이기 때문에 인자로 받을 수 있음
    // -> const 없이 String& rhs 형태로 작성되었다면, r-value 를 인자로 받을 수 없었을 것임
    String(String&& rhs) // 이동 생성자는, 이렇게 r-value 에 대한 참조를 인자로 받음
    {
        // 얕은 복사가 일어나도록 코드 작성
        cout << "String(String&&) : " << this << endl;
        len = rhs.len;
        strData = rhs.strData;
        rhs.strData = NULL;
        // res 객체가 소멸할 때, 메모리 공간이 할당 해제되지 않게 해야 함
        // -> res.strData 가 빈 공간을 가리키도록 만들면 됨
        // -> 이렇게 해주지 않으면, res.strData 와 {임시 객체}.strData 모두, 같은 공간을 가리키는 상황이 됨
    }
    // 이렇게 이동 생성자를 선언해주면, 임시 객체가 생성될 때, 깊은 복사 대신 얕은 복사가 일어남 (복사 -> 이동)
    // -> 임시 객체를 a 객체에 대입할 때에만 깊은 복사가 일어남
    // -> 이는, 이동 대입 연산자를 구현해서 해결할 수 있음

    // ?? 이번에도 영상과 다르게 이동 생성자가 호출되지 않음;
    // -> 찾아봤는데, 복사 생략(copy elision) 라는 컴파일러 최적화 기술 때문인 것 같음
    // -> 컴파일러가 복사/이동할 대상에 임시 객체를 직접적으로 구성할 수 있도록 함 (복사/이동 생성, 소멸자 쌍이 생략됨)
    // 참고 링크 : https://stackoverflow.com/questions/13099603/c11-move-constructor-not-called-default-constructor-preferred

    ~String()
    {
        cout << "~String() : " << this << endl;
        release();
        strData = NULL;
    }

    String& operator=(const String& rhs)
    {
        cout << "String &operator=(const String&) : " << this << endl;
        if (this != &rhs) {
            release();
            len = rhs.len;
            alloc(len);
            strcpy(strData, rhs.strData);
        }
        return *this;
    }
    String& operator=(String&& rhs) // String&& operator=() 형태로 선언하면 r-value 를 반환하겠다는 뜻이 되버림
    {
        cout << "String& operator=(String&&) : " << this << endl;
        len = rhs.len;
        strData = rhs.strData;
        rhs.strData = NULL;
        return *this; // String a = b = c; 처럼 대입 연산자가 중첩되는 경우 때문
    }
    // a 객체에 임시 객체가 대입되는 시점에도, 깊은 복사 대신 얕은 복사가 일어나게 됨 (복사 -> 이동)
    // -> 결과적으로, 메모리 동적 할당은 딱 한 번만 일어나게 됨
    // -> getName 함수 내부에서 res 객체가 생성된 시점에 할당, main 함수가 종료되면서 a가 소멸할 때 할당 해제
    // -> 메모리 공간을 정말로 필요한 만큼만 사용하게 됨

    // res -> {임시 객체} -> a 순으로 객체 복사가 일어남
    // -> 여기서, {임시 객체} 는 r-value 임
    // -> {임시 객체} 가 a 객체에 복사되는 상황을 코드로 표현하면, a = {임시 객체}; 형태가 될 것임
    // -> r-value 참조를 매개 변수로 받는 이동 대입 연산자가 호출된 것임
    // -> 이동 대입 연산자가 없을 때 복사 대입 연산자가 호출되던 이유는 매개 변수로 const String& rhs 를 받기 때문임 (위에서도 설명함)

    char* GetStrData() const
    {
        return strData;
    }
    int GetLen() const
    {
        return len;
    }
    void SetStrData(const char* str)
    {
        cout << "void SetStrData(const char*) : " << this << ", " << str << endl;
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }

private:
    void alloc(int len)
    {
        strData = new char[len + 1];
        cout << "strData allocated : " << (void*)strData << endl;
    }
    void release()
    {
        delete[] strData;
        if (strData)
            cout << "strData released : " << (void*)strData << endl;
    }

    char* strData;
    int len;
};

String getName()
{
    cout << "===== 2 =====" << endl;
    String res("Doodle");
    cout << "===== 3 =====" << endl;
    return res;
}

int main()
{
    String a;
    cout << "===== 1 =====" << endl;
    a = getName();
    cout << "===== 4 =====" << endl;
}
