// 상속의 개념, 생성자와 소멸자에 대해서 살펴봤었음
// 이번 시간에는 상속 관계에서, 생성자와 소멸자가 어떤 식으로 작동하는지에 대해서 알아볼 것임

#include <iostream>

using namespace std;

class Ice { // 얼음
public:
    Ice() { cout << "Ice()" << endl; }
    ~Ice() { cout << "~Ice()" << endl; }
};

class Pat { // 팥
public:
    Pat() { cout << "Pat()" << endl; }
    ~Pat() { cout << "~Pat()" << endl; }
};

// 얼음과 팥을 활용해, 팥빙수라는 클래스를 만들어볼 것임
// -> 팥빙수말고도 다양한 빙수가 있음
// -> Bingsoo 라는 클래스를 만든 후, 여러 파생 클래스를 만들어 다양한 빙수들을 나타내볼 것임
/*
class Bingsoo { // 빙수
public:
    Bingsoo() { cout << "Bingsoo()" << endl; }
    ~Bingsoo() { cout << "~Bingsoo()" << endl; }

private:
    Ice ice; // 모든 빙수에는 얼음이 들어감
    // -> Ice* ice; 로 선언한 경우, 생성자 호출과 함께 초기화줘야 함
    // -> ice = new Ice; => 객체 생성 + 생성된 객체의 주소 할당
    // -> 멤버는 생성자가 호출되기 전에 생성된다는 뜻
};
*/
class Bingsoo {
public:
    Bingsoo()
    {
        cout << "Bingsoo()" << endl;
        ice = new Ice; // Ice 객체는 이 부분에서 생성됨
    }
    virtual ~Bingsoo() // 이렇게 virtual 키워드를 추가해 가상 함수로 만들어주면, 동적 바인딩이 일어남
                       // -> 기반 클래스에서는 파생 클래스의 멤버에 접근할 수 없음
                       // -> 때문에, 웬만하면 클래스의 소멸자는 가상 함수로 선언해주는 것이 좋음
    {
        cout << "~Bingsoo()" << endl;
        delete ice;
    }

private:
    Ice* ice;
    // Ice 객체에 대한 포인터이므로, 멤버 생성 시 Ice 클래스의 생성자가 호출되지 않음
    // -> Bingsoo() => Ice()
    // -> ~Bingsoo() => ~Ice()
};

/*
class PatBingsoo : public Bingsoo {
public:
    PatBingsoo() { cout << "PatBingsoo()" << endl; }
    // 파생 클래스의 생성자가 호출될 때, 기반 클래스의 기본 생성자도 호출됨 (+ 관련 클래스의 생성자도 마찬가지)
    // -> PatBingsoo() => Bingsoo(), Pat(), Ice()
    ~PatBingsoo() { cout << "~PatBingsoo()" << endl; }
    // 파생 클래스의 소멸자가 호출될 때도, 기반 클래스의 소멸자도 호출됨 (+ 관련 클래스의 소멸자도 마찬가지)
    // -> ~PatBingsoo() => ~Bingsoo(), ~Pat(), ~Ice()

private:
    Pat pat; // 팥빙수에는 팥이 들어감
    // -> Pat* pat; 로 선언한 경우, 소멸자 호출과 함께 제거해줘야 함
    // -> delete pat; => 메모리 할당 해제 + 포인터(변수) 제거
    // -> 소멸자가 호출된 후에 멤버가 제거된다는 뜻
};
*/
class PatBingsoo : public Bingsoo {
public:
    PatBingsoo()
    {
        cout << "PatBingsoo()" << endl;
        pat = new Pat;
    }
    ~PatBingsoo()
    {
        cout << "~PatBingsoo()" << endl;
        delete pat;
    }

private:
    Pat* pat;
};

/*
int main()
{
    PatBingsoo* p = new PatBingsoo;
    // Ice() -> Bingsoo() -> Pat() -> PatBingsoo()
    // 기반 클래스의 멤버 -> 기반 클래스 -> 파생 클레스의 멤버 -> 파생 클래스
    delete p;
    // ~PatBingsoo() -> ~Pat() -> ~Bingsoo() -> ~Ice()
    // 파생 클래스 -> 파생 클레스의 멤버 -> 기반 클래스 -> 기반 클래스의 멤버

    // => 소멸자는 무조건 생성자가 호출된 순서의 역순으로 호출됨

    // 팥빙수를 새로 만들려는 상황
    // -> 팥빙수(파생 클래스)의 기반이 되는 빙수(기반 클래스)를 만들어야 함
    // -> 빙수(클래스)를 만들려면 얼음(멤버)이 필요함
    // => 얼음으로 빙수를 만들고, 팥을 챙겨서 팥빙수를 만듬

    // 팥빙수를 먹으려는 상황
    // -> 팥빙수(클래스)를 먹을 땐, 팥(멤버)을 먼저 먹게될 것임
    // -> 팥빙수(파생 클래스)를 먹는 과정에서 빙수(기반 클래스) 부분이 사라져감
    // => 팥빙수를 먹으면서 팥을 먹게 되고, 먹는 과정에서 빙수의 얼음을 먹게 됨
}
*/

// 소멸자도 가상 함수가 될 수 있음
int main()
{
    Bingsoo* p = new PatBingsoo; // Bingsoo 객체를 가리키는 포인터로, PatBingsoo 객체를 가리키고 있다고 가정
                                 // -> ~PatBingsoo() 가 호출되지 않음
                                 // -> 아래의 delete p; 부분에서 정적 바인딩이 일어나기 때문
                                 // -> 소멸자에 대해서도 동적 바인딩이 일어나게 해야 함
                                 // -> 할당 해제할 메모리 공간의 크기가 커질수록, 효율 부분에서 차이가 커짐
    delete p;
}

// 다음 시간에는 형 변환에 대해서 다뤄볼 것임
// -> 그런 다음, 객체 지향에서 아주 중요한 주제인 상속, 다형성에 대한 설명을 마무리해볼 것임
