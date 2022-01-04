#include <stdio.h>

int main()
{
    /*
    char str[] = "Hello";

    printf("%s\n", &str[0]); // == printf("%s\n", str);
    // %s = 문자열의 끝을 나타내는 NULL 문자(\0)가 나올때까지, 문자열의 내용을 하나씩 출력
    */

    char strings[3][10] = { "Hello", "World", "Doodle" };

    /*
    for (int i = 0; i < 3; i++) {
        printf("%s\n", &strings[i][0]); // &strings[i][0] == strings[i]
        // printf("%s\n", strings[i]);
    }
    */

    char* p_str[3];

    for (int i = 0; i < 3; i++) {
        p_str[i] = strings[i];
    }

    for (int i = 0; i < 3; i++) {
        printf("%s\n", p_str[i]);
    }
}
