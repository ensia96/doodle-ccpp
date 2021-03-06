// 지금까지는 언어적인 측면을 많이 봤다면, 9부 부터는 프로그램의 성능을 향상시키는 방법 위주로 다룰 것임
// 프로그램의 성능은 크게 시간적인 측면에서의 성능, 공간적인 측면에서의 성능으로 나뉨
// 공간적인 성능 == 메모리를 얼마나 많이 사용하는가
// 즉, 메모리 관리를 어떻게 하는지, 작업을 얼마나 효율적으로 처리하는지에 따라 성능이 달라짐

// 동적 할당 : 유동적으로 메모리를 할당하는 것
// -> 지금까지의 메모리 할당 = 변수 선언 등 -> 정적 할당에 해당됨(정적 할당이라는 표현은 자주 쓰이진 않음)

// 정적 할당 : int a;
// 동적 할당 : 프로그램 실행 중에 변수를 메모리에 할당하는 것
// -> 소속 공간에 영향을 받는 정적 할당과는 다르게, 원하는 크기의 메모리 공간을 원하는 기간동안 사용
// -> 필요하면 할당, 필요 없어지면 할당 해제

#include <iostream>

using namespace std;

int main()
{
    // int a(5);
    // int a = int(5); <- 동적 할당의 기본적인 표현 (이렇게 생성자 호출과 비슷한 형태로도 적을 수 있음)
    int* a = new int(5); // new == 연산자
                         // new 뒤에 생성자 호출 형태의 구문이 오면, 내부적으로는 아래처럼 동작함
                         // -> 대입 연산이므로 우변에 있는 코드가 먼저 실행됨
                         // -> 메모리상의 임의의 위치에 int형 자료를 하나 저장할 수 있는 공간이 만들어짐
                         // -> 이렇게 저장된 자료의 경우, 주소값 외에는 특별한 값이 없음
                         // -> new int(5) 에서 반환된 주소값이 포인터 a에 저장됨

    cout << a << endl;
    cout << *a << endl;

    *a = 10;

    cout << a << endl;
    cout << *a << endl;

    delete a; // 동적 할당 후에는 항상, 이렇게 할당된 메모리를 해제해줘야함
              // -> 따로 해제해주지 않으면, 할당받은 공간이 사용중인 상태로 계속 남아있게 됨 (메모리 낭비)
}
