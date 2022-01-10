// 문자열 : 문자들이 열거

#include <stdio.h>

int main()
{
    /*
    // char arr[100];
    //  char arr[100] = { 'H', 'e', 'l', 'l', 'o', ... };
    //  char arr[100] = "Hello, world!";
    char arr[] = "Hello, world!";

    printf("%s\n", arr);

    printf("배열의 크기 : %d\n", sizeof(arr) / sizeof(char));
    // 13글자인 문자열의 크기 = 14
    // ASCII 코드 0번 = NULL 문자 -> 문자열의 끝을 나타냄

    // char arr[] = "abc" => { 'a', 'b', 'c', '\0' }; => \0 == NULL 문자
    */

    char s[100]; // -> s = string = 문자열
    // 문자열 자료형이 따로 있어서, 문자 배열은 자주 안 씀
    // 문자열은 실제로는 이렇게 문자들의 배열 형태로 구현됨

    scanf("%s", s); // scanf("%s", &s); -> x

    printf("%s\n", s);
}
