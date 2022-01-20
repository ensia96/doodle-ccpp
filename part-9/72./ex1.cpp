#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    Item(int num) // 변환 생성자
        : num(num)
    {
        cout << "Item(int)" << endl;
    }
    Item(string name) // 변환 생성자
        : name(name)
    {
        cout << "Item(string)" << endl;
    }
    Item(int num, string name)
        : num(num)
        , name(name)
    {
        cout << "Item(int, string)" << endl;
    }
    /*
    // 이렇게, 변환 생성자 앞에도 explicit 키워드를 붙여줄 수 있음
    explicit Item(int num)
        : num(num)
    {
        cout << "Item(int)" << endl;
    }
    explicit Item(string name) // 변환 생성자
        : name(name)
    {
        cout << "Item(string)" << endl;
    }
    explicit Item(int num, string name)
        : num(num)
        , name(name)
    {
        cout << "Item(int, string)" << endl;
    }
    */

    // int로의 형 변환 연산자 오버로딩
    // -> 변환 연산자는 다른 연산자들과 오버로딩하는 방식이 다름
    // -> (int) 연산자를 함수 형태로 표현하려다 보니, 반환하는 자료형을 먼저 명시하지 않는 형태가 되버림
    // -> 연산자 별로 오버로딩 방식이 다르니, 무작정 외우기보단 써보면서 조금씩 익혀가길 권장함
    operator int() const // 변환 연산자는 반환 자료형을, 함수 이름 앞에 명시하지 않고, 함수 이름으로 표시함
                         // -> 객체 내용이 바뀌지 않음을 보장하기 위해 상수형 메서드로 선언
    {
        return num;
    }
    // string으로의 형 변환 연산자 오버로딩
    operator string() const
    {
        return to_string(num) + " : " + name;
        // to_string 함수는 <string> 헤더 파일에 정의되어 있음
        // -> 인자로 받은 숫자를 string 으로 바꿔주는 역할을 함
        // -> to_string(num) == num 변수에 저장된 숫자 값이 문자열 형태로 반환될 것임
        // -> + 연산자를 이용해 여러 문자열 또는 string 객체를 합칠 수 있음
    }

    /*
    // 묵시적 형 변환이 의도치 않은 형태로 일어나기도 함
    // -> 묵시적 형 변환을 아예 막아버리는 기법도 있음
    // -> 이렇게, 앞에 explicit 키워드를 붙여주면 됨 (명시적으로 형 변환이 일어날 때만 실행하겠다는 뜻)
    explicit operator int() const
    {
        return num;
    }
    explicit operator string() const
    {
        return to_string(num) + " : " + name;
    }
    */

    void print()
    {
        cout << num << " : " << name << endl;
    }

private:
    int num;
    string name;
};

void println(string s) // 입력받은 문자열을 한 줄로 출력해주는 함수
{
    cout << s << endl;
}
void println(int n) // 이렇게, println 함수를 오버로딩했다고 가정
                    // -> 인자로 오는 자료의 형에 따라 다르게 처리해줄 수 있음 (확장)
                    // -> 아래의 println(i8); 부분에서 오류가 뜸
                    // -> 형이 명시되어있지 않아서, 어떤 함수를 실행할지가 모호해지기 때문
                    // -> 변환할 형을 꼭 명시해줘야 함 (묵시적 형 변환이 일어나서 번거로워짐)
{
    cout << n << endl;
}

int main()
{
    Item i1 = Item(1);
    Item i2(2);
    Item i3 = 3;
    i3 = 3;            // 묵시적 변환
    Item i4 = (Item)4; // 명시적 변환

    Item i5(5);
    i5 = (string) "stone";

    Item i6(1, "grass");
    Item i7 = { 2, "dirt" };
    i7 = { 2, "dirt" };
    Item i8 { 3, "wood" };

    /*
    int itemNum = (int)i8; // 적절한 변환 함수가 없다는 내용의 오류가 뜸 (형 변환 불가)
                           // -> 묵시적 형 변환도 안 됨 (int itemNum = i8;)
                           // -> C, C++ 에서는 (int) 와 같은 명시적 형 변환도 연산자로 취급함 (변환 연산자)
                           // -> 따라서, 연산자 오버로딩이 가능함
    */
    int itemNum1 = (int)i8; // 명시적 형 변환
    int itemNum2 = i7;      // 묵시적 형 변환 (이렇게 변환 연산자가 오버로딩된 상태에선, 묵시적 형 변환도 허용됨)
    cout << itemNum1 << endl;
    cout << itemNum2 << endl;

    string itemName = (string)i7; // explicit 키워드에 의해 묵시적 형 변환이 막혀서 오류가 뜸

    /*
    println((string)i8); // 명시적 형 변환
    println(i8);         // 묵시적 형 변환
    // void aaa(double a) { }
    // aaa(3);
    // 이렇게 호출해도, 내부적으로 int 형이 double 형으로 변환되어서, 오류는 안 남
    // -> 프로그램의 실행 과정에서, 알게 모르게, 묵시적 형 변환이 알아서 일어난다는 뜻
    // -> println(i8); 의 경우, i8 객체가 자동으로 string 형으로 변환됨
    // -> 형 변환을 따로 안해도 알아서 처리됨 == 겁나 간편함 == 묵시적 형 변환이 생겨난 배경 (원래는 불편했음)
    */

    println((string)i8);
    println((int)i8); // 함수 오버로딩 때문에 명시적 형 변환으로 변경

    // 9부 연습문제
}
// 형 변환에 대해서 더 궁금한 점은, 따로 인터넷을 통해 알아보길 권장함
// -> 나중에, 상속과 같은 다른 개념들을 배운 후에 더 자세하게 알아볼 예정
