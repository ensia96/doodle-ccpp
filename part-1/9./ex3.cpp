/*
3. 알파벳을 입력받아서 그 다음 알파벳을 출력하는 프로그램을 만들어 보세요. (Z제외)
*/

#include <stdio.h>

int main()
{
    /*
    char alphabet;

    scanf("%c", &alphabet);

    printf("%c\n", alphabet+1);
    */

    char alpha;

    scanf("%c", &alpha);

    // printf("%c\n", alpha + 1);

    char nextalpha = alpha + 1;

    printf("%c\n", nextalpha);
}
