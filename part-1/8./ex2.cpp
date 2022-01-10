#include <stdio.h>

int main()
{
    /*
    char a;

    printf("문자 입력 : ");

    scanf("%c", &a); // 문자가 숫자 형태(ASCII)로 a에 대입됨

    printf("당신이 입력한 문자는 %c입니다.\n", a); // 숫자 a가 %c에서 문자로 변환됨

    printf("%c의 ASCII 값 : %d\n", a, a); // 숫자 a가 %d에서는 숫자 그대로 출력됨
    */

    // 과제 : 숫자를 입력받아서, 그 숫자에 해당하는 ASCII 문자를 출력하는 프로그램 만들기

    int a;

    printf("숫자 입력 : ");

    scanf("%d", &a);

    printf("%d의 ASCII 문자 : %c\n", a, a);
}
