#include <iostream>

using namespace std;

// 1. □ 부분에 알맞은 기호를 넣고, 출력 결과를 예측해보세요.

int main()
{
    /*
    int a = 10, b = 20, c = 30;
    int* p = □a;
    int& r = □b;
    int** pp = □p;  // p라는 포인터를 가리키는 더블 포인터 pp (24강)
    int*(&rp) = □p; // p라는 포인터를 가리키는 레퍼런스 변수 rp (51강)

    r = c / □p;
    rp = □c;
    □pp = 40;
    □p = 50;
    *pp = □a;
    □rp = 60;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << *p << endl;
    cout << r << endl;
    cout << **pp << endl;
    cout << *rp << endl;
    */
    /*
    int a = 10, b = 20, c = 30;
    int* p = &a;
    int& r = b;
    int** pp = &p; // p라는 포인터를 가리키는 더블 포인터 pp (24강)
    int*(&rp) = p; // p라는 포인터를 가리키는 레퍼런스 변수 rp (51강)

    r = c / *p;
    rp = &c;
    **pp = 40;
    *p = 50;
    *pp = &a;
    *rp = 60;

    // 여기까진 맞춤..

    cout << a << endl;    // 50
    cout << b << endl;    // 3
    cout << c << endl;    // 60
    cout << *p << endl;   // 50
    cout << r << endl;    // 3
    cout << **pp << endl; // 50
    cout << *rp << endl;  // 60

    // 여기서 틀림 ㅜㅠㅜㅠ
    // -> 두들낙서님에게도 그림 안 그리고 풀기는 어려운 문제라고 함
    // -> int*(&rp) = p; 부분부터 잘못 생각한 듯..
    */
    int a = 10, b = 20, c = 30;
    int* p = &a;
    int& r = b;
    int** pp = &p; // p라는 포인터를 가리키는 더블 포인터 pp (24강)
    int*(&rp) = p; // p라는 포인터를 가리키는 레퍼런스 변수 rp (51강)

    r = c / *p;
    rp = &c;
    **pp = 40;
    *p = 50;
    *pp = &a;
    *rp = 60;

    cout << a << endl;    // 60
    cout << b << endl;    // 3
    cout << c << endl;    // 50
    cout << *p << endl;   // 60
    cout << r << endl;    // 3
    cout << **pp << endl; // 60
    cout << *rp << endl;  // 60

    // p -> a
    // r -> b
    // pp -> p
    // rp -> p

    // 참조 변수는 참조할 대상이 정해지면, 다른 대상을 참조할 수 없게 됨
}
