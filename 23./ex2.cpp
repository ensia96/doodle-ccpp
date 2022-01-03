#include <stdio.h>
#include <string.h>
// include = 뒤에 오는 파일을 포함하겠다는 뜻

int main()
{
    /*
    char str[] = "Hello"; // -> size = 5

    // size = sizeof(str) / sizeof(char) - 1

    char str[100];

    scanf("%s", str); // input : Hello -> size = 99

    int len;

    len = strlen(str); // 문자열 길이를 반환하는 함수

    printf("문자열의 길이는 %d\n", len);
    */

    /*
    char str1[] = "Hello";
    char str2[100];

    strcpy(str2, str1); // 문자열 전체를 복사하는 함수

    printf("str2의 값 : %s\n", str2);
    */

    /*
    char str[100] = "Hello ";
    strcat(str, "World!"); // 특정 문자열 뒤에 다른 문자열을 붙여주는 함수
    strcat(str, "World!");
    strcat(str, "World!");
    strcat(str, "World!");

    printf("%s\n", str);
    */

    char str1[] = "sample";
    // char str1[] = "simple";
    char str2[] = "simple";

    int cmp = strcmp(str1, str2); // 두 문자열을 비교한 후, 결과를 반환하는 함수
                                  // str1이 str2보다(사전순) 앞에 있다면 음수, 뒤에 있다면 양수, 같다면 0
    // int cmp = strcmp(str1, str2);
    printf("%d\n", cmp);
}
