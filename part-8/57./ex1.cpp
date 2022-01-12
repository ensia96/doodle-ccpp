#include <iostream>

using namespace std;

class Complex {
public:
    /*
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(double real_ = 0, double imag_ = 0) // 이전 강의에서 배웠듯, 이렇게 매개 변수에 기본값을 지정해줄 수 있음
                                                // -> 위의 생성자 함수와 매개 변수의 개수가 같아짐
                                                // -> 어떤 생성자 함수를 실행해야 하는지 모호해짐 (모호성 발생)
                                                // -> 어차피 동작은 똑같으므로, 그냥 위의 생성자 함수를 지워도 됨
                                                // -> 이렇게 하면, 오버로딩 없이 생성자를 정의할 수 있음
    {
        real = real_;
        imag = imag_;
    }
    */

    // 초기화 목록 : 생성자에서 지원하는 기능
    // -> 멤버 변수를 초기화하는 좀 더 편한(?) 방법임

    /*
    Complex()
    {
        real = 0;
        // real(0); // <- 단순히 변수에 값을 대입할 때는 괄호를 사용할 수 없음
        imag = 0;
    }
    Complex(double real_, double imag_)
    {
        real = real_;
        imag = imag_;
    }
    */

    // 이런 문법을 초기화 목록이라고 함 -> 내용이 따로 없을 때 쓰기 좋음

    Complex()
        : real(0)
        , imag(0)
    {
    }
    /*
    Complex(double real_, double imag_)
        : real(real_)
        , imag(imag_)
    {
    }
    */

    /*
    Complex(double real, double imag)
    {
        real = real; // 이렇게 하면, 양쪽 모두 매개 변수로 인식됨
        imag = imag;
    }
    */
    Complex(double real, double imag)
        : real(real)
        , imag(imag) // 이렇게 하면, 문법 때문에 구별이 됨 -> <멤버 변수>(<매개 변수>)
    {
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
    int a(5); // <- 생성자라고 볼 수도 있음 (변수를 초기화하는 방법 중 하나)

    Complex c1;
    Complex c2 = Complex(2, 3);
    // Complex c2 = Complex(2); // 이렇게 매개 변수를 하나만 주면, 다른 하나는 기본값인 0으로 지정됨
    Complex c3(2, 3);
    Complex c4 = { 2, 3 };
    Complex c5 = Complex { 2, 3 };
    Complex c6 { 2, 3 };

    cout << "c1 = " << c1.GetReal() << ", " << c1.GetImag() << endl;
    cout << "c2 = " << c2.GetReal() << ", " << c2.GetImag() << endl;
    cout << "c3 = " << c3.GetReal() << ", " << c3.GetImag() << endl;
}
