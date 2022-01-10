// printf 는 콘솔에 출력, fprintf 는 파일에 출력

// 다른 문자열에 출력을 하거나, 문자열에서 입력을 받아올 수 있는 함수가 있음
// sscanf / sprintf

#include <stdio.h>

int main()
{
    /*
    char str[] = "450";
    int n;

    sscanf(str, "%d", &n);    // str 로 부터 %d 형식으로 입력을 받은 값을 n에 저장
    printf("n의 값 : %d\n", n);
    */

    int n = 450;
    char str[100];

    sprintf(str, "%d", n); // n 의 값을 %d 형태로 받아와서 str 이라는 변수에 출력(저장)
    printf("%s\n", str);
}
