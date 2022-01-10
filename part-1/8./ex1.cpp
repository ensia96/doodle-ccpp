// char : 1바이트 정수형 (int : 4바이트)
// character : 문자
// -> 반각(half width)  문자ABC, abc, 123, _+\;/#% 등만 가능
// -> 한글, 한자, 일본어와 같은 전각(full width) 문자는 안됨 x

#include <stdio.h>

int main()
{
    char a = 67;

    printf("%c\n", a);
    printf("%c\n", 'C');
    printf("%d\n", 'C'); // 'C' == 67
}

// ASCII : American Standard Code for Information Interchange
// 문자를 숫자에 대응시키는 표준 (미국에서 정함)
