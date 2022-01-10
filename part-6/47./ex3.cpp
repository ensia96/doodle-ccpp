#include <stdio.h>

int main()
{
    /*
    FILE* in = fopen("part-6/47./ex3.cpp", "r"); // 현재 파일에 대한 입력 스트림
    char ch;
    while (!feof(in)) { // feof 함수는 파일을 끝까지 읽었을 때 true 반환 (아닐 땐 false 반환)
                        // eof == 'end of file' 의 약자 -> 파일의 끝에서 true 반환
                        // ! 연산자 때문에 파일을 읽는 동안은 true 다가, 끝에 도달한 순간 false 가 됨
        fscanf(in, "%c", &ch);
        printf("%c", ch);
    }

    fclose(in);
    // 실행하면, 파일 내용을 그대로 출력함
    // 마지막에 뭐가 더 출력됨 -> feof 함수의 특성상, 파일의 마지막 내용을 읽은 바로 다음 시점까지 동작함
    */

    FILE* in = fopen("part-6/47./ex3.cpp", "r");
    char ch;
    while (fscanf(in, "%c", &ch) != EOF) { // 이렇게 구현해도 됨
                                           // fscanf 함수는 입력받은 문자열의 길이를 반환함
                                           // 파일 끝에 도달하면 EOF 라는 값을 반환함
                                           // -> 위의 방식처럼 한번 더 실행되지 않음
                                           // -> 마지막에 다른 값이 더 출력되지 않음
                                           // (참고로, EOF 는 -1 이라는 값을 가짐)
        printf("%c", ch);
    }

    fclose(in);
}
