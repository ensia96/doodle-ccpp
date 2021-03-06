# 2진법, 자료형 총정리

10진법 : 자리수가 늘어날 때마다 수가 10배씩 커짐

    12345 = 10000 + 2000 + 300 + 40 + 5
          = 1*10^4 + 2*10^3 + 3*10^2 + 4*10^1 + 5*10^0

2진법 : 자리수가 늘어날 때마다 수가 2배씩 커짐, 0과 1로만 구성

    100110(2) = 1*2^5 + 1*2^2 + 1*2*1 = 38

    int - 32비트 = 4바이트 => 00000000 00000000 00000000 00000000

    비트 = 2진수 자리수의 개수 -> 0과 1을 표현할 수 있는 자리수

    5 = 101(2) = 00000000 00000000 00000000 00000101
    37 = 100101(2) = 00000000 00000000 00000000 00100101

    8비트 = 1바이트

        바이트 : 컴퓨터에서 자료를 처리하는 가장 작은 단위

        => 과학에서 분자를 따지는 단위(1mol) 와 비슷

---

자료형 : 크게 정수형과 실수형으로 나뉨

정수형

    char = 1바이트 = 문자를 담는 데 쓰임

    short = 2바이트

    long = 4바이트 = -2147483648(-2*31) ~ +2147483647(2^31 - 1)

    long long = 8바이트

    int = 시스템에 따라서 자동 결정 -> 대체로 long으로 결정됨

실수형

    float = 4바이트

    double = 8바이트

---

unsigned, signed

    컴퓨터에서 자료의 첫번째 비트는 부호를 저장하는 데 쓰임(양수일 땐 0, 음수일 땐 1)

    (의외로, -1 = 11111111 11111111 11111111 11111111 임;)

    unsigned <- 첫번째 비트(부호) 를 무시하겠다는 뜻 = 음수를 표현할 필요가 없을 때 활용

        unsigned int a; -> 0 ~ +4294967295(2^32 - 1)

        unsigned double f;

---

정수, 실수형 이외에 void, bool 자료형도 있음

void : 값을 반환하지 않는 함수에 대한 자료형

bool : 참, 거짓을 저장하는 자료형

    0, 1만 따지면 되니 1비트일 것 같지만, 1바이트 공간을 사용함

    -> 컴퓨터가 자료를 처리하는 최소 단위가 1바이트이기 때문

    -> char 자료형을 쓰는 것과 별 차이가 없음
