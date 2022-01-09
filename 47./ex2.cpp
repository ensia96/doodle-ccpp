#include <stdio.h>

int main()
{
    FILE* in;
    int n;

    /*
    in = fopen("47./intput.txt", "r"); // 이렇게 오타가 발생할 수도 있음
                                       // -> 존재하지 않는 파일을 열게 되므로 오류 발생
                                       // => NULL 포인터를 반환하게됨

    printf("in = %d\n", in); // 주소값을 가리키는 변수이므로 값이 있음 -> 0이 출력됨
    // NULL == 0 -> 위에서 0이 출력되는 것은 '포인터가 NULL이다.', 즉, '아무것도 가리키고 있지 않다.' 를 의미함
    */

    in = fopen("47./intput.txt", "r"); // 파일이 존재하지 않을 가능성에 대해 주의해야 함
                                       // 파일이 유실될 수도 있음

    if (in != NULL) { // 이렇게, 파일 스트림이 NULL 포인터가 아닐때만 작업을 수행하도록 하면 됨
        // NULl 을 써도 되고, nullptr 을 써도 됨(내 PC에서는 안됨;)
        fscanf(in, "%d", &n);
        printf("%d\n", n);
        fclose(in);
    }
}
