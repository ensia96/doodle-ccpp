// 처음에 코드가 엄청 많이 바뀌어 있어서 당황;
// -> 동적 할당, 할당 해제 구문이 생성자 ~ 소멸자 구간에 많이 등장함
// -> 그래서, 각 구문을 별도의 함수로 빼둠 + 함수 내부에서 어떤 동작이 일어났는지 출력하도록 구현해 둠
// -> 일부 코드를 지워둔 문제 파일이 있으니, 직접 채워보면서 헷갈리거나 이해가 잘 안 되던 부분들을 해소하길 권장함 (+ 구현 연습)
// -> 해답 파일도 같이 있으니, 영상보고 다 따라칠 필요도 없음

// 지난 시간까지는 얕은 복사로 인해 생기는 문제를 해결하는 방법에 대해 알아봄
// -> 이번 시간에는 반대로, 깊은 복사로 인해 생기는 문제들을 해결하는 방법에 대해서 알아볼 것임
// -> 깊은 복사로 인해 생기는 문제는 얕은 복사를 통해 해결해야 함 (???)

// 깊은 복사에도 나름대로의 단점이 있음
// -> 어떤 객체를 복사할 때마다, 메모리 공간을 새로 할당한 후에 원본 객체에 있던 자료를 복사해와야 함
// -> 아래처럼 strcpy 함수를 사용하는 경우, 문자열에 포함된 문자를 하나하나씩 복사하게 됨
// -> 1mb 크기의 사진을 복사한다고 가정하면, 1mb 를 전부 다 복사해야 하기 때문에 시간이 오래 걸릴 것임
// -> 이렇게, 객체의 크기가 크면 클수록, 깊은 복사를 위해 더 많은 작업을 수행해야 함
// -> 간혹, 깊은 복사가 쓸모 없어지는 상황이 있음

#include <iostream>

using namespace std;

class String {
public:
    String()
    {
        cout << "String() : " << this << endl;
        // 구현
        strData = NULL;
        len = 0;
    }
    String(const char* str)
    {
        cout << "String(const char*) : " << this << endl;
        // 구현
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }
    String(const String& rhs) // 복사 생성자
    {
        cout << "String(const String&) : " << this << endl;
        // 구현
        len = rhs.len;
        alloc(len);
        strcpy(strData, rhs.strData);
    }

    ~String()
    {
        cout << "~String() : " << this << endl;
        /*
        // 구현
        release();
        // ㄲㅂ.. NULL 써주려다가 소멸자라서 그냥 넘어갔는데..
        */
        release();
        strData = NULL;
    }

    String& operator=(const String& rhs) // 복사 대입 연산자
    {
        cout << "String &operator=(const String&) : " << this << endl;
        // 구현
        if (this != &rhs) {
            release();
            len = rhs.len;
            alloc(len);
            strcpy(strData, rhs.strData);
        }
        return *this;
    }

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
        /*
        // 구현
        operator=(str);
        // 인자로 String 객체 대신 문자열을 받아서 따로 구현해줘야 하는구나..
        // -> 매개 변수가 어떻게 설정되어 있는지도 잘 살펴봤어야 했는데..
        */
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

String getName() // String 객체를 반환하는 함수임
{
    cout << "===== 2 =====" << endl;
    String res("Doodle"); // res 객체는 String(const char*) 생성자를 통해서 생성됨
    cout << "===== 3 =====" << endl;
    return res; // == return String("Doodle");
                // -> 반환되기 전에 어떤 일이 일어나는지 확인하기 위해 이렇게 작성한 것일 뿐
}

// getName 함수 내부에는 res 객체가 있음
// -> 함수가 종료되면 소멸자가 호출되면서, res 객체가 자동으로 소멸됨
// -> res 객체는 main 함수의 a = getName(); 부분에서 사용되어야 함
// -> res 객체가 a에 대입되는 시점에, res 객체는 이미 소멸한 상태
// -> a에는 res 객체가 아닌 다른 객체가 대입된다는 것을 알 수 있음
// -> getName 함수가 반환되는 순간, res 객체가 이름 없는 임시 객체에 복사됨
// -> 그런 다음, 함수가 종료되면서, res 객체가 소멸함
// -> 임시 객체가 a에 대입됨
// -> 대입 연산이 끝난 후, 임시 객체는 자동으로 소멸함
// -> 깊은 복사는 총 2번(res -> {임시 객체}, {임시 객체} -> a) 일어남

// 근데, 실제로 필요한 객체는 a 뿐이기 때문에, 깊은 복사가 2번이나 일어날 필요가 없음
// -> 대입 연산 후에 사라질 객체들을 굳이 만들어서, 깊은 복사까지 하는 상황임

// res 객체의 strData 가 {임시 객체} 에 복사될 땐, 복사 생성자를 통해 깊은 복사가 일어남
// {임시 객체} 의 strData 가 a 객체에 복사될 땐, 대입 연산자를 통해 깊은 복사가 일어남

// 임시 객체를 없앨 수는 없으니, 복사 생성자 대신 다른 종류의 생성자를 호출하도록 해볼 것임
// -> 임시 객체가 생성될 때, 깊은 복사 대신, 얕은 복사가 일어나게 할 것임
// -> 새로운 공간을 할당하지 않고, 기존에 사용 중이던 공간을 사용하게 될 것임 (더 효율적)
// -> a에 임시 객체가 대입되는 시점에도, 깊은 복사가 일어나지 않도록 해볼 것임
// -> 깊은 복사가 아예 일어나지 않도록 바꾸겠다는 뜻임

// 여기서 주의해야할 것은, 얕은 복사 이후에 일어나는 할당 해제에 관한 문제임
// -> 이미 해제된 공간에 대해 할당 해제를 시도하게 되는 문제가 있었음
// -> 같은 공간에 대해서는 할당 해제가 한 번만 일어나도록 해야함
// -> 얕은 복사를 해도 소멸자가 한 번만 호출되게 만드는 방법에 대해 알아보고, 직접 구현해볼 것임

// 좋은 소식 : C++ 에서, '이동 시맨틱(Move semantics)' 이라는, 얕은 복사에 관련된 새로운 컨셉을 지원함
// -> 이 컨셉이 등장하기 전까지는, 복사 생성자를 사용하는 등, 다른 방법으로 얕은 복사를 구현해야 했음
// -> res, {임시 객체}, a 객체는 모두 strData 라는 char 형 포인터를 포함하고 있음

// 프로그램의 흐름상, res 객체가 선언되는 시점에 생성자에 의해 임의의 메모리 공간이 할당됨
// -> res.strData 와 메모리 공간 사이의 연결 관계를 끊고, {임시 객체}.strData 가 메모리 공간을 가리키게 함
// -> 다시, {임시 객체}.strData 와 메모리 공간 사이의 연결 관계를 끊고, a.strData 가 메모리 공간을 가리키게 함
// -> 임의의 메모리 공간을 사용하는 주체가 res, {임시 객체}, a 객체 순서로 바뀜
// -> 이렇게, 한 객체에 속해있던 자원(자료가 저장된 메모리 공간)이 다른 객체로 이동하는 양상을 이동(move) 이라고 함
// (나는 '특정 공간에 대한 주도권이 한 객체에서 다른 객체로 넘어간다.' 는 식으로 이해함)

// 이동 시맨틱에 포함된 이동 생성자와 이동 대입 연산자에 대해서 알아볼 것임 (깊은 복사용 대입 연산자는, 복사 대입 연산자라고 부름)
// -> 이동 시맨틱을 구현하려면 r-value 가 필요함 (전에 대충 설명하고 넘어갔었음)
// -> 이동 시맨틱에 대한 설명이 길어져서, 이번 시간에는 r-value 에 관한 내용까지만 알아볼 것임 여담)
// 객체 복사 파트는 추상적인 개념 위주여서, 지루하고, 이해하기 어려운 편임 (프로그래머는 추상적인 개념에 친숙해야 함)
// C++ 을 능숙하게 다루려면 머리가 좋아야 함 (경험적으로도 커버되긴 함, 프로그래밍 입문용으로는 어려운 편에 속함)
// C++ 은 무언가를 구체적으로 구현하기에 좋은 언어임 (객체 지향 언어지만, 기호에 따라 다른 패러다임을 적용해도 됨)
// 물론, C# 처럼 알아서 이것저것 해주는 언어에 비해, 직관적이지 않은 부분이 많은 편임 (모두 직접 배워서, 알아서 해야 함)

int main()
{
    String a; // a 객체는 String() 생성자를 통해서 생성됨
    cout << "===== 1 =====" << endl;
    a = getName();
    cout << "===== 4 =====" << endl;
    // 상식적으로 생각해보면, 깊은 복사는, getName() 에서 반환된 객체가 a에 복사될 때, 딱 1번만 일어나야함
    // -> 직관적으로 보면, 깊은 복사가 일어날만한 곳을 찾기 힘듬
    // -> 복사 생성자 호출한 적 없음 + a = getName(); 부분에서 대입 연산자가 딱 한번만 호출됨
    // -> 그런데 3 ~ 4 번 구간에서 복사 생성자가 호출됨 (내 pc에서는 안 됨)
    // -> 대입 연산자로 함수 반환값을 복사했을 때 복사 생성자가 호출된 이유를 제대로 이해하려면, 임시 객체에 대해서 알아야 함

    /*
    // r-value 의 어원은 '등호의 우변에만 올 수 있는 값' 임 (좌변에는 올 수 없는 값을 뜻함)
    int a = 5;
    a = 5; // 이것도 됨
    a = a; // 이것도 됨

    // 이렇게, 좌변에 올 수 있는 값은 우면에도 올 수 있음 -> l-value
    // C++ 에서, 모든 값은 l-value 와 r-value 로 나뉨
    */

    // 이동 시맨틱에서 r-value 를 사용해야 하는 이유를 l-value 의 특성과 함께 생각해보자

    /*
    int x = 2;
    x = 5;     // 이건 됨
    x + 3 = 5; // 이건 그냥 방정식;
               // -> 컴퓨터에게 방정식을 풀라고 명령하는 것과 같은 표현;
               // -> 이런 표현은 불가능함
               // -> x는 메모리에 저장되어 있지만, x + 3 이라는 식은 연산 결과로 바뀔 뿐, 자체가 메모리에 저장되지는 않기 때문
               // -> 값을 대입할 공간이 없는데, 어떤 값을 대입하라고 하는 것과 같은 격
               // 결론) 식의 연산 결과는 r-value 다.
    */

    /*
    int f() { return 5; } // 이렇게, 별 의미 없는 함수가 있다고 가정
    f() = 1; // ??
             // -> 될 리가 없음, 절.대.안.됨
             // -> 함수가 반환한 값에 다른 값을 대입한다는 표현 자체가 넌센스임
             // -> f() 자체를 함수로 생각하면, 그냥 방정식이 되버림 (말도 안 되는 방정식)
             // -> 함수의 반환값 자체는 임시 객체이므로, 메모리상에 저장되긴 함
             // -> 이렇게, 메모리 상에 저장되어 있음에도, f() 에 대입할 수 없는 이유는, f() 또한 r-value 이기 때문
             // -> 메모리 상에 저장된 자료는 l-value 이지만, 임시 객체는 예외임
             // 결론) 함수가 반환한 결과, 즉, 임시 객체는 r-value 다.
    */

    /*
    a = getName(); // 등호 연산자를 통해, 복사 대입 연산자가 호출됨
                   // -> 여기서, getName() 은 임시 객체, 즉, r-value 임
                   // -> 대입 연산자가 r-value 에 대해서는 다르게 동작하게 만들면 됨 (복사 대입 연산자를 호출하지 않도록)
                   // -> 매개 변수로 r-value 를 받는 함수를 새로 만들면 됨 (추가적으로 오버로딩을 한다는 느낌)
                   // -> 기존에 오버로딩된 복사 대입 연산자 대신, 새로 만든 함수가 호출될 것임
    */

    /*
    String&& r = getName(); // getName() 에서 반환되는 것은 임시 객체임
                            // -> 여기서, && 를 r-value 참조자(r-value 참조 선언자) 라고 부름
                            // -> 이렇게 작성하면, 변수 r을 통해 getName() 이라는 r-value 를 참조할 수 있음
                            // -> 즉, 새로 만들 함수의 매개 변수의 자료형을 r-value 참조자 형태로 지정하면 됨
    */
}