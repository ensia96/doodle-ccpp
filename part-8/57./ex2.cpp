// 시h 분m 초s

#include <iostream>

using namespace std;

class Time {
public:
    // Time(5);         // 5초 저장
    // Time(5, 0);      // 5분 저장
    // Time(2, 37, 54); // 2시간 37분 54분 저장

    /*
    // Time(int h_ = 0, int m_ = 0, int s_ = 0) // 이렇게 하면 초만 받을 수 없음
    Time(int s_ = 0, int m_ = 0, int h_ = 0) // 이렇게 하면 분, 초만 받을 수 없음
    {
    }
    */

    // 함수 오버로딩으로 처리하기

    /*
    Time()
    {
        h = 0;
        m = 0;
        s = 0;
    }
    Time(int s_)
    {
        s = s_;
    }
    Time(int m_, int s_)
    {
        m = m_;
        s = s_;
    }
    Time(int h_, int m_, int s_)
    {
        h = h_;
        m = m_;
        s = s_;
    }
    */

    // 초기화 목록으로 바꿔줄 수 있음
    // -> 생성자 위임이라는 기능을 활용할 수 있음

    // 생성자 위임 : 어떤 특정한 생성자가 '자기 자신이 속한 클래스 내의 다른 생성자' 를 호출할 수 있게 해주는 기능

    /*
    Time() // 이 생성자를 제외한 나머지 생성자들은 모두 서로 공통된 부분이 있음 -> 이런 상황에서 쓰기 좋음
        : h(0)
        , m(0)
        , s(0)
    {
    }
    Time(int s_)
    {
        s = s_;
    }
    Time(int m_, int s_)
    {
        m = m_;
        s = s_;
    }
    Time(int h_, int m_, int s_)
    {
        h = h_;
        m = m_;
        s = s_;
    }
    */

    Time()
        : h(0)
        , m(0)
        , s(0)
    {
    }
    Time(int s_)
        : Time()
    {
        s = s_;
    }
    Time(int m_, int s_)
        : Time(s_)
    {
        m = m_;
    }
    Time(int h_, int m_, int s_) // 왼쪽의 생성자 함수가 호출된 경우 => Time(1, 2, 3);
                                 // 콜론(:) 뒤쪽의 내용을 먼저 확인함 -> Time(m_, s_) => Time(2, 3)
                                 // Time(m_, s_) 에서도 똑같이 콜론 뒤쪽 내용부터 확인함 -> Time(s_) => Time(3)
                                 // Time(s_) 에서도 똑같이 콜론 뒤쪽 내용부터 확인함 -> Time()
                                 // 이제, Time() 부터 실행됨 -> h = 0; m = 0; s = 0;
                                 // 그 다음으로 Time(s_) 가 실행됨 -> h = 0; m = 0; s = s_ = 3;
                                 // 다음으로 Time(m_, s_) 가 실행됨 -> h = 0; m = m_ = 2; s = 3;
                                 // 마지막으로 Time(h_, m_, s_) 가 실행됨 -> h = h_ = 1; m = 2; s = 3;
        : Time(m_, s_)
    {
        h = h_;
    }

    // 이렇게 생성자 위임을 하면, 코드 길이가 많이 줄어듬 -> 코드가 짧아지는만큼 실수할 여지도 적어짐

    // 오버로딩으로 처리하면, 하나를 수정해도, 관련된 함수들까지 전부 다 수정해야 함
    // 하지만, 생성자 위임을 하면 수정할 부분만 수정해줘도 나머지가 다 수정됨 -> 수정하기 쉬움

    // private: // 편의를 위해 일단 생략
    int h;
    int m;
    int s;
};

int main()
{
    Time t1;
    Time t2(5);
    Time t3(3, 16);
    Time t4(2, 42, 15);

    cout << "t1 : " << t1.h << ":" << t1.m << ":" << t1.s << endl; // t1 : 0:0:0
    cout << "t2 : " << t2.h << ":" << t2.m << ":" << t2.s << endl; // t2 : 0:0:5
    cout << "t3 : " << t3.h << ":" << t3.m << ":" << t3.s << endl; // t3 : 0:3:16
    cout << "t4 : " << t4.h << ":" << t4.m << ":" << t4.s << endl; // t4 : 2:42:15
}
