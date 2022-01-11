// C++ 스타일의 함수
// C++ 에서는 함수를 좀 더 유연하게 사용하도록 여러 기능을 제공함

// overload (함수 오버로딩)
// over load -> 필요 이상으로 (over) 불러온다 (load) -> 직역하면 다중 정의 -> 함수 여러 번 정의하기

#include <iostream>

// using namespace std; // swap 이라는 변수 이름이 들어있음

/*
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swapd(double& a, double& b) // 이름이 겹치니 뒤에 d 붙여주기
{
    double tmp = a;
    a = b;
    b = tmp;
}

void swapp(int*(&a), int*(&b))
// 포인터를 바꾸는 함수이니 뒤에 p 붙여주기
// int*(&a) == int 형 포인터를 가리키는 참조 변수임
// void swapp(int*& a, int*& b) // 이렇게 괄호 없이도 사용 가능
{
    int* tmp = a; // 임시 포인터 -> a라는 참조 변수가 가리키고 있는 포인터에 저장된 주소값이 저장됨
    a = b;
    b = tmp;
}

int main()
{
    int a = 20, b = 30;
    double da = 2.222, db = 3.333; // swap -> 자료형이 맞지 않아서 문제가 발생 -> 또 다른 swap 함수를 만들어야 함
    int *pa = &a, *pb = &b;

    swap(a, b);
    swapd(da, db);
    swapp(pa, pb);

    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;

    std::cout << "da : " << da << std::endl;
    std::cout << "db : " << db << std::endl;

    std::cout << "*pa : " << *pa << std::endl;
    std::cout << "*pb : " << *pb << std::endl;
}
*/

// 자료형마다 swap 함수가 필요

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(double& a, double& b)
{
    double tmp = a;
    a = b;
    b = tmp;
}

void swap(int*(&a), int*(&b))
{
    int* tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 20, b = 30;
    double da = 2.222, db = 3.333;
    int *pa = &a, *pb = &b;

    swap(a, b);
    swap(da, db);
    swap(pa, pb);
    // 이렇게, 함수 이름이 모두 똑같아도 다 자동으로 구분됨 = 함수 오버로딩
    // -> 컴파일러 자체가 매개 변수의 형을 인식한 후, 가장 적합한 함수를 찾아줌

    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;

    std::cout << "da : " << da << std::endl;
    std::cout << "db : " << db << std::endl;

    std::cout << "*pa : " << *pa << std::endl;
    std::cout << "*pb : " << *pb << std::endl;
}
