#include <stdio.h>

int main()
{
    /*
    int n;

    scanf("%d", &n);
    printf("%d\n", n);
    */

    /*
    // FILE* in; // 스트림 / 파일을 가리키는 포인터
    int n;

    // in = fopen("input.txt", "r"); // <- segmentation fault -> 상대 경로 때문에 발생;

    in = fopen("47./input.txt", "r"); // <- 실행 위치 기준으로 파일을 입력해야함
    // 읽을 파일의 이름, 작업 내용 => 파일을 가리키는 포인터를 반환
    // r = 읽기 (read), w = 쓰기 (write)

    fscanf(in, "%d", &n); // in 이라는 스트림에 대해 scanf
    printf("%d\n", n);
    */

    /*
    FILE *in, *out; // 입력 스트림과 출력 스트림
    int n;

    in = fopen("47./input.txt", "r");
    out = fopen("47./output.txt", "w");

    fscanf(in, "%d", &n);
    fprintf(out, "%d\n", n); // out 이라는 스트림에 대해 printf

    // 위에서 파일을 열었으면 닫아줘야함.
    // -> main 함수가 종료되는 동시에 파일을 자동으로 닫아서 따로 코드로 적지 않아도 됨

    // 동시에 여러 개의 파일을 여는 경우, 오류가 발생할 수 있음 -> 열고 닫고를 하나씩 반복해야 함

    // 이렇게 하나씩 닫아줄 수 있음 -> 웬만하면 사용하고 제때 닫아주는 것이 좋음
    fclose(in);
    fclose(out);
    */

    FILE *in, *out;
    int n;

    in = fopen("47./input.txt", "r");
    out = fopen("47./output.txt", "a");
    // w(write, 쓰기) 로 파일을 열면, 기존 내용을 출력 내용으로 아예 대체함
    // a(append, 덧붙이기) 로 파일을 열면, 기존 내용에 출력 내용을 추가함

    fscanf(in, "%d", &n);
    fprintf(out, "%d\n", n);

    fclose(in);
    fclose(out);
}
