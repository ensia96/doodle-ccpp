// 이번 시간부터 다뤄볼 주제는 상속 관계에서의 형 변환임
// -> 가장 기본적인 형태의 형 변환은 C 언어 파트에서 살펴봤었음 (int -> double 등)
// -> 어떤 클래스의 객체를 완전히 다른 자료형으로 변환하는 방법에 대해서도 살펴봤었음 (C++ 변환 생성자 등)
// -> 이번 시간에는 이러한 형 변환들과는 조금 다름

// class Base { ... }; class Derived : public Base { ... }; Base* b = new Derived;
// -> 이렇게, 기반 클래스의 객체를 가리키는 포인터로 파생 클래스의 객체를 가리킬 수 있음
// -> 이것이 가능한 이유는, 바로 업캐스팅(upcasting) 이라는 형 변환 기능 때문임
// -> new Derived 의 자료형은 Derived 클래스의 객체를 가리키는 포인터임
// -> 이 new Derived 라는 포인터가 Base* b 에 저장되는 것임
// -> 여기서부터 이미, 서로 다른 두 자료형 간에 뭔가가 일어났음을 알 수 있음
// -> 파생 클래스의 포인터는 별도의 처리 없이도 기반 클래스의 포인터로 바뀔 수 있음

// Upcasting : 자식 클래스 포인터 -> 부모 클래스 포인터 (묵시적)

#include <iostream>

using namespace std;

/*
int main()
{
    double a = 1; // 1은 int 형이지만, 묵시적 형 변환이 일어나서 double 형인 a 변수에 대입될 수 있는 것임
                  // -> 묵시적 형 변환 기능이 없었다면, 명시적으로 형을 변환해줘야 했을 것임 (1 -> (double)1)
                  // -> 물론, int 와 double 사이의 관계는 기반 클래스와 파생 클래스 사이의 관계와는 조금 다름
                  // -> 중요한 것은, int 형 자료였던 1이 묵시적으로 double 형 자료로 변환되었다는 것임

    Base* b = new Derived;

    // 이렇게, 기반 클래스의 포인터에 파생 클래스의 포인터를 대입하는 형태로도 생각해볼 수 있음
    Derived* d = new Derived;
    Base* b = d;
    // 이것이 가능한 이유는, 묵시적으로 형 변환이 일어났기 때문 (파생 클래스 -> 기반 클래스)
    // -> 이렇게, 파생 클래스에서 기반 클래스로 올라가는(up) 형태의 형 변환(casting) 을 업캐스팅이라고 함
    // -> 이러한 업캐스팅은 묵시적으로 일어남

    // 업캐스팅이 별 문제없이 수행되는 이유는,
    // -> 파생 클래스가 기반 클래스보다 많은 속성을 가지고 있기 때문

    // 남자와 총각 예시에서 살펴봤듯, 남자가 가질 수 있는 속성보다 총각이 가질 수 있는 속성이 더 많음
    // -> 때문에, 총각을 남자로 취급하는 것은 전혀 문제가 없음
    // -> 반대로, 남자를 총각으로 취급하는 것은 상황에 따라 가능할 수도, 불가능할 수도 있음

    // 파생 클래스의 객체를 부모 클래스의 객체로 취급해도 딱히 문제는 없음
    // -> 일반적으로는 문제되지 않지만, 전혀 문제가 없는 것은 아님
}
*/

class Animal { // 동물
public:
    /*
    float xpos = 1; // 2차원 평면 상에 존재함
    float ypos = 2;
    */

    // 임의로 좌표 지정
    float xpos = 1;
    float ypos = 2;
};

class FlyingAnimal : public Animal {
public:
    float zpos = 3; // 날아다니는 동물이기 때문에, z 좌표가 필요함
};

/*
void printAnimals(Animal a[], int n) // 동물 정보가 담긴 배열과 배열의 크기를 입력받아, 각 동물의 위치를 출력하는 함수
{
    for (int i = 0; i < n; i++) {
        cout << "(" << a[i].xpos << ", " << a[i].ypos << ")" << endl;
    }
}
*/

void printAnimals(Animal** a, int n) // 포인터 배열에 대해서 동작하도록 수정해줘야 함
{
    for (int i = 0; i < n; i++) {
        cout << "(" << a[i]->xpos << ", " << a[i]->ypos << ")" << endl;
    }
}

int main()
{
    /*
    Animal* a = new Animal[10];
    printAnimals(a, 10);
    delete[] a;
    */

    /*
    FlyingAnimal* a = new FlyingAnimal[10];
    printAnimals(a, 10);
    // printAnimals(Animal a[], int n) == printAnimals(Animal* a, int n)
    // -> FlyingAnimal* a 가 Animal* a 에 전달되는 과정 중에 업캐스팅이 일어남 (오류는 안 뜸)
    // -> 좌표가 이상하게 출력됨 (본질적인 문제 : 함수를 잘못 사용했음)
    // -> 하지만, 오류가 뜨진 않았음. 이는, 해당 코드가 문법적으로는 문제가 없었다는 뜻임
    // -> float 형의 크기는 4바이트임
    // -> FlyingAnimal 객체는 float 3개 크기, Animal 객체는 float 2개 크기임
    // -> FlyingAnimal[10] 는 FlyingAnimal 객체의 배열임
    // -> Animal a[] 는 인자로 전달받은 배열을 Animal 객체의 배열로 취급함
    // -> [(xpos, ypos, zpos), (xpos, ypos, zpos), ...] -> [(xpos, ypos), (zpos, xpos), (ypos, zpos), ...]
    // -> 배열, 포인터 처리 방식 때문에 생긴 문제임

    // 기반 클래스 포인터로 파생 클래스 객체를 가리킬 때는 문제가 없음
    // -> 객체 배열에 대해서는 문제가 생길 수 있음
    // -> 포인터 자료형의 크기에 따라 인덱싱이 다르게 적용되기 때문
    // -> 객체 배열 대신 객체에 대한 포인터의 배열을 사용하면 됨
    // -> printAnimals 함수를 클래스에 맞게 오버로딩해도 되긴 함
    */
    Animal** a = new Animal*[10]; // Animal* 10개를 저장하는 배열을 동적으로 할당
                                  // -> new Animal*[10] = 동적으로 할당된 배열의 0번 인덱스를 가리키는 포인터를 반환함
                                  // -> Animal* 를 가리키는 포인터 => Animal**
                                  // -> 포인터 배열 선언 완료
    for (int i = 0; i < 10; i++) {
        a[i] = new FlyingAnimal; // 동적으로 객체를 할당받음 + 그 객체를 가리키는 포인터를, 포인터 배열의 각 인덱스에 대입
    }
    printAnimals(a, 10);
    for (int i = 0; i < 10; i++) {
        delete a[i]; // 동적으로 할당받은 객체들에 대한 할당 해제
    }
    delete[] a; // 동적으로 할당받은 포인터 배열에 대한 할당 해제
}
