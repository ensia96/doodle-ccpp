// 이번 시간에는 가상 함수와 동적 바인딩에 대해서 알아볼 것임

// 지난 시간는 정적 바인딩에 대해서 살펴봤음
// class Base { ... }; class Derived : public Base { ... }; Base* p = Derived C;
// p->member; // == Base::member O, Derived::member X
// 정적 바인딩 == 포인터의 자료형이 컴파일 시점의 자료형으로 고정되는 것
// 동적 바인딩 == 포인터의 자료형이 현재 가리키고 있는 대상의 자료형에 따라 바뀌는 것

#include <iostream>

using namespace std;

class Weapon { // 무기(게임)
public:
    Weapon(int power) // 무기 생성
        : power(power)
    {
        cout << "Weapon(int)" << endl;
    }

    /*
    void Use() // 무기 사용(공격)
    {
        cout << "Weapon::Use()" << endl;
    }
    */
    // 아래처럼 virtual 키워드를 붙여주면, main 함수에서 살펴봤던 정적 바인딩 관련 문제를 해결할 수 있음
    virtual void Use() // 가상 함수
    {
        cout << "Weapon::Use()" << endl;
    }

private:
    int power; // 무기의 공격력
};

class Sword : public Weapon { // 칼(무기)
public:
    Sword(int power)
        : Weapon(power) // 부모 객체로 생성 위임
    {
        cout << "Sword(int)" << endl;
    }

    void Use() // 오버라이딩 (무기마다 특징이 다름)
    {
        cout << "Sword::Use()" << endl;
        Swing(); // 칼을 사용하면 칼 휘두르기 동작이 수행됨
    }

private:
    void Swing() // 칼 휘두르기
    {
        cout << "Swing sword." << endl;
    }
};

class Magic : public Weapon { // 마법 무기
public:
    Magic(int power, int manaCost)
        : Weapon(power)
        , manaCost(manaCost)
    {
        cout << "Magic(int, int)" << endl;
    }

    void Use()
    {
        cout << "Magic::Use()" << endl;
        Cast(); // 마법 무기를 사용하면 마법 사용 동작을 수행함
    }

private:
    void Cast() // 마법 사용 (Sword::Swing 메서드와 비슷한 역할, 동작이 다름)
    {
        cout << "Cast magic." << endl;
    }
    int manaCost; // 마법 무기를 쓸 때 필요한 마나를 저장해줘야 함
};

int main()
{
    Sword mySword(10);    // 공격력이 10인 칼 생성
    Magic myMagic(15, 7); // 공격력이 15, 마나 소모가 7인 마법 무기 생성

    mySword.Use();
    myMagic.Use();

    // mySword 생성 : Weapon(int) -> Sword(int)
    // myMagic 생성 : Weapon(int) -> Magic(int, int)
    // => 생성자가 실행될 때, 초기화 목록 부분의 코드가 먼저 실행됨

    // mySword 사용 : Sword::Use() -> Swing sword.
    // myMagic 사용 : Magic::Use() -> Cast magic.

    Weapon* currentWeapon;    // 무기를 가리키는 포인터 (장착 중인 무기 / 무기 포인터여서 칼, 마법 무기 모두 가능)
    currentWeapon = &mySword; // 칼 장착
    currentWeapon->Use();     // 현재 들고 있는 무기 사용 -> 정적 바인딩 -> Weapon::Use()
                              // -> Weapon::Use 메서드에 virtual 키워드 추가 -> Sword::Use()
    currentWeapon = &myMagic;
    currentWeapon->Use();

    // 정적 바인딩의 경우,
    // -> 프로그램이 컴파일되는 시점에는, currentWeapon 포인터가 어떤 대상을 가리키게 될 지 알 수 없음

    // 프로그래머 : "... 응애ㅐㅐ"
    // 컴파일러 : (에~라 모르겠다~ 얘는 Weapon 포인터니까 Weapon 클래스꺼 갖다 쓰지 뭐~ ㅋㅋ)

    // 메서드에 virtual 키워드를 추가하면, 가상 함수로 취급됨
    // -> 임의로 작성해 둔 가상의 함수 (다른 대상이 호출되어야 할 수도 있음)
    // -> 호출 대상이 될 수도 있고, 안 될 수도 있다는 의미

    // 동적 바인딩의 경우,
    // -> 프로그램이 컴파일되는 시점에는, Use 함수가 어떤 식으로 호출될 지 알 수 없음

    // 프로그래머 : "어.. 걔는 Weapon 클래스꺼로 호출될 수도 있고, 다른 클래스꺼로 호출될 수도 있음! ㅋ"
    // 컴파일러 : (Aㅏ.. 애매하네.. 일단은 이대로 두고, 실제로 호출될 때 확인해봐야겠다;)
}
