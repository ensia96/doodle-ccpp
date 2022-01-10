// 유용한 함수들

// scanf, printf 로 모든 입출력을 처리할 수 있음
// -> 경우에 따라 시간이 너무 오래 걸리거나, 사용하기 불편한 상황이 생김
// -> 이러한 점을 보완하는 함수들이 있음

// getchar / putchar : 문자 (char) 입출력 처리 함수
// -> printf, scanf 에서도 %c 를 사용해 처리할 수 있음
// -> 하지만, 이 함수들의 속도가 훨씬 더 빠름
// => 문자 한두개에 대한 입출력을 처리할 땐 이 함수들을 사용하는 것이 더 효율적임

// gets / puts : 문자열 (sting) 입출력 처리 함수
// -> 살짝 위험성이 있음 -> 일부 버젼에선 없어졌다고 함 -> gets_s 를 사용
// -> 실행해보면 'warning: this program uses gets(), which is unsafe.' 에러 뜸

#include <stdio.h>

int main()
{
    /*
    char ch;

    ch = getchar(); // 매개 변수가 없음, 입력받은 문자를 바로 반환함
    // getchar(ch); // call-by-value -> 실제 ch 값은 바뀌지 않음
    putchar(ch); // 문자열을 그대로 출력함
    */

    char str[100];

    gets(str); // 배열 이름 자체가 포인터여서 call-by-reference 가 됨
               // 한 줄 전체를 입력받음
               // scanf("%s", ...)  으로 받으면, 공백을 기준으로 하나씩 입력받게 됨
    // str = gets(); // 주소값을 바꾸겠다는 의미가 되버림
    puts(str);
}
