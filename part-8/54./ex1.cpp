// struct
// class
// 구조체와 클래스의 차이점은 딱 하나밖에 없음

// 이전 강의에서는 C 언어에서의 구조체를 배운 것임

// C 언어에서 C++ 로 넘어오면서, 객체 지향 프로그래밍이라는 새로운 패러다임을 추구하게 됨 (이외에도 많은 패러다임들이 구현됨)

// 가장 중요한 것은 구조체에 여러 기능들이 추가되었다는 것 -> 대부분 객체 지향 프로그래밍과 관련이 있는 기능들임

// 대충 요약)
// C 언어의 구조체와 C++ 의 구조체는 완전히 다름 (엄청나게 많은 기능들이 추가됨)
// 그러한 C++ 의 구조체와 클래스 사이에는 딱 한 가지 차이점이 있음

// ===========================================================================================================================

// 클래스 = 자료 저장 + 자료 처리 = 변수 + 함수 | <- 가장 기본적인 기능 | 변수, 함수를 묶어놓은 형태 (구조체와 비슷)
// 클래스(타입) : 특정한 용도를 수행하기 위한 변수와 함수를 모아 둔 '틀' (자료형)
// 객체(오브젝트) : 그 틀을 이용하여 찍어낸 개체 (변수, 메모리 상의 공간)

// ===========================================================================================================================

// int a, b, c; // int 자료형의 특징을 가지는 변수를 만들 수 있음 -> int 는 붕어빵 틀, a, b, c 는 붕어빵
// 클래스도 붕어빵 틀이라고 생각할 수 있음 -> 어떤 변수를 만들기 위한 틀 -> 자료형으로 볼 수도 있음 (구조체도 자료형이었음)
// C++ 에서는 클래스를 타입(type) 이라고도 부름
// 이러한 클래스로 생성된 것(틀을 이용해 찍어낸 것) 이 객체 -> 객체 지향 프로그래밍의 '객체'
// 객체(오브젝트, object) -> 객체 지향 프로그래밍 = object oriented programming, OOP

#include <iostream>

using namespace std;

/*
struct TV {
    bool powerOn;
    int channel;
    int volume;
};

int main()
{
    TV lg;
    lg.powerOn = true;
    lg.channel = 10;
    lg.volume = 50;
    // lg.volume = 120; // 볼륨 범위가 0 ~ 100 인데, 120을 주면 문제
}
*/

/*
struct TV {
    bool powerOn;
    int channel;
    int volume;

    void setVolume(int vol)
    {
        if (vol >= 0 && vol <= 100) {
            volume = vol;
        }
    }
};

int main()
{
    TV lg;
    lg.powerOn = true;
    lg.channel = 10;
    lg.setVolume(50);
    lg.volume = 400; // setVolume 함수를 사용하지 않으면 문제는 그대로
                     // -> volume 변수를 setVolume 함수에서만 접근하도록 하고 싶다는 발상에 도달함
}
*/

// 접근 제어 지시자의 종류
// private, protected, public

// private : 개인적으로만 사용 -> 밖에서는 접근 불가, 내부에서만 접근 가능
// public : 공공으로 사용

// 캡슐화 : 내부적인 속성들은 보호하면서, 외부 사용자들에게 내부 속성에 접근할 수 있는 인터페이스를 제공하는 것
// -> private 을 이용해 변수들을 캡슐 안에 가둬놓고, public 으로 공개된 함수들을 써서 관리하는 방식

/*
struct TV {
private: // 이 지시자의 아래쪽에 있는 요소들은 모두 private
    bool powerOn;
    int channel;
    int volume;

public:
    void on()
    {
        powerOn = true;
        cout << "TV를 켰습니다." << endl;
    }

    void off()
    {
        powerOn = false;
        cout << "TV를 껐습니다." << endl;
    }

    void setChannel(int cnl)
    {
        if (cnl >= 1 && cnl <= 999) {
            channel = cnl;
            cout << "채널을" << cnl << "(으)로 바꿨습니다." << endl;
        }
    }

    void setVolume(int vol)
    {
        if (vol >= 0 && vol <= 100) {
            volume = vol;
            cout << "볼륨을" << vol << "(으)로 바꿨습니다." << endl;
        }
    }
};
*/

// 구조체와 함수의 차이점
// 구조체에서는 private 을 따로 적어주지 않으면 모두 public 이 됨
// -> 접근 제어 지시자를 따로 안 써주면 기본적으로 public 의 특성을 지니게 됨
// -> struct 를 쓸 땐 private 을 항상 써줘야 함

class TV { // 선언자를 struct 에서 class 로 바꿔주기만 하면 클래스가 됨
    // 기본적으로 private 속성을 지니게 되므로, 이렇게 private 을 따로 적어주지 않아도 됨
    bool powerOn;
    int channel;
    int volume;

public: // 반대로, public 은 따로 지정해줘야함
    void on()
    {
        powerOn = true;
        cout << "TV를 켰습니다." << endl;
    }

    void off()
    {
        powerOn = false;
        cout << "TV를 껐습니다." << endl;
    }

    void setChannel(int cnl)
    {
        if (cnl >= 1 && cnl <= 999) {
            channel = cnl;
            cout << "채널을" << cnl << "(으)로 바꿨습니다." << endl;
        }
    }

    void setVolume(int vol)
    {
        if (vol >= 0 && vol <= 100) {
            volume = vol;
            cout << "볼륨을" << vol << "(으)로 바꿨습니다." << endl;
        }
    }
};

// 캡슐화는 OOP 의 4가지 특성 중 하나임

int main()
{
    TV lg;

    lg.on();
    lg.setChannel(10);
    lg.setVolume(50);
    // 이렇게 하면, TV의 채널과 볼륨을 좀 더 안전하게 처리할 수 있음
    lg.setChannel(-73);
}
