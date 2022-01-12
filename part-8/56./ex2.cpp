#include <iostream>

using namespace std;

// 생성자 : 멤버 변수 초기화
// 소멸자 : 메모리 해제

// 복소수(real, imag) -> 실수, 허수
class Complex {
public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(double real_, double imag_) // 생성자 오버로딩
    {
        real = real_;
        imag = imag_;
    }

    double GetReal()
    {
        return real;
    }
    void SetReal(double real_)
    {
        real = real_;
    }
    double GetImag()
    {
        return imag;
    }
    void SetImag(double imag_)
    {
        imag = imag_;
    }

private:
    double real;
    double imag;
};

int main()
{
    Complex c1;                    // 매개 변수가 없는 생성자가 호출됨
    Complex c2 = Complex(2, 3);    // 매개 변수가 있는 생성자가 호출됨
    Complex c3(2, 3);              // 바로 위의 표현과 똑같이 동작함
    Complex c4 = { 2, 3 };         // 생성자는 이런 식으로도 호출할 수 있음
    Complex c5 = Complex { 2, 3 }; // 중괄호를 사용해서 초기화를 할 수 있음 -> 용도가 있음 -> 어려운 개념들이 있어서 나중에
    Complex c6 { 2, 3 };

    cout << "c1 = " << c1.GetReal() << ", " << c1.GetImag() << endl;
    cout << "c2 = " << c2.GetReal() << ", " << c2.GetImag() << endl;
    cout << "c3 = " << c3.GetReal() << ", " << c3.GetImag() << endl;
}
