// 묵시적(암시적) 형 변환 implicit conversion
// 명시적 형 변환 explicit conversion
// 형 변환은 이렇게, 크게 두 종류로 나뉨

#include <iostream>
#include <string> // iostream 에 있는 string 과는 다른 string 임

using namespace std;

class Item {
public:
    Item(int num) // 변환 생성자
                  // -> Item i1 = Item(1); => 일반 생성자
                  // -> Item i4 = (Item)4; => 변환 생성자
                  // -> 역할에 따라, 일반 생성자가 될 수도, 변환 생성자가 될 수도 있음
                  // -> 변환 생성자라는 생성자 종류가 따로 있는 것이 아니고, 형 변환을 담당할 수 있으면 변환 생성자라고 부르는 정도
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

    void print()
    {
        cout << num << " : " << name << endl;
    }

private:
    int num;
    string name;
};

int main()
{
    Item i1 = Item(1);
    Item i2(2);
    Item i3 = 3;
    i3 = 3;            // 묵시적 변환
    Item i4 = (Item)4; // 명시적 변환

    /*
    i3 = 3;            // Item(int) 생성자가 호출됨
                       // -> 이동 대입 연산자가 호출된다고 뜸 + 정수가 i3 라는 Item 객체에 할당됨 => ?
                       // -> 이렇게 어떤 객체에 다른 자료를 대입할 때, 컴파일러는 대입할 자료의 형을 변환할 수 있는지부터 확인함
                       // -> 마침, 클래스 내부에 변환 생성자가 있으니, 그것을 활용하여 자료를 변환함 (생성자 호출)
                       // -> 자료를 Item 객체로 변환하는 과정에서, 새로운 객체가 생성됨 (임시 객체)
                       // -> 이렇게 생성된 임시 객체가 이동 연산자를 통해, i3 객체에 복사됨
    Item i4 = (Item)4; // Item(int) 생성자가 호출됨
                       // -> Item(int) 생성자를 주석 처리하면, 'int 를 Item 으로 변환할 때 사용할 생성자가 없다.' 라는 오류가 뜸
                       // -> 반대로 말하면, Item(int) 생성자가 int 를 Item 으로 변환하는 역할까지 하고 있었다는 뜻

    Item i4 = (Item)4 // == Item i4 = 4;
                      // == Item i4 = Item(4);
                      // 굳이 명시적으로 형 변환을 하는 사람도 있음
                      // -> Item(4) 형태로 작성하던, (Item)4 형태로 작성하던, 내부적으로는 똑같이 동작함
    */

    // Item i5("stone"); // == Item i5 = "stone";

    Item i5(5);
    /*
    i5 = "stone"; // C++ 은 C 의 확장판이기 때문에, "stone" 문자열을 const char [] 형으로 인식함 (완벽한 string 이 아니라는 뜻)
                  // -> const char [] 형 자료를 인자로 받는 함수도 오버로딩해줘야 함
                  // -> 그냥 아래처럼 const char [] 형을 string 으로 변환해주면 됨
    */
    i5 = (string) "stone"; // == i5 = string("stone");
                           // -> Item(string) 생성자에 의해 string 형 자료가 Item 객체로 변환됨

    Item i6(1, "grass");     // 가장 기본적인 생성자 호출 형태
    Item i7 = { 2, "dirt" }; // 구조체를 배울 때 함께 살펴봤었던 선언 형태임
                             // -> 이렇게 작성해도, Item(int, string) 생성자가 호출됨
                             // -> Item i3 = 3; 과 비슷한 표현이라고 볼 수 있음
    i7 = { 2, "dirt" };      // 인자가 2개 이상일 때, 묵시적으로 형을 변환하고 싶으면 이런 식으로 작성하면 됨
                             // -> C++ 11 문법임
                             // -> 2011년에 C++ 이 개선되면서, 새로 추가됨
                             // -> 이전 버전의 컴파일러에서는 정상적으로 컴파일되지 않을 수도 있음
    Item i8 { 3, "wood" };
    // 이렇게 중괄호로도 묵시적 형 변환을 할 수 있음

    i1.print();
    i2.print();
    i3.print();
    i4.print();
    i5.print();
    i6.print();
    i7.print();
    i8.print();

    // 이번 시간에는 어떤 자료가 객체로 변환되는 식의 묵시적 형 변환에 대해서 알아봤음
    // 다음 시간에는 객체가 어떤 자료로 변환되는 식의 묵시적 형 변환에 대해서 알아볼 것임
    // -> cout << i5 << endl;
}
