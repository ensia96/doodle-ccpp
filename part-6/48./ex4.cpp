// exit(0);
// 말 그대로 프로그램을 그 자리에서 종료 시켜버리는 함수 -> 함수의 return 과 비슷함

// main 함수에서는 return 0 을 쓰나 exit(0) 을 쓰나 크게 차이가 없음
// 다른 함수에서는 return 을 쓰면 함수만 종료됨, exit(0) 을 사용하면 프로그램이 종료됨

#include <stdio.h>
#include <stdlib.h> // exit 함수도 표준 라이브러리 헤더 파일에 있음

int main()
{
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        int n;

        scanf("%d", &n);

        if (n <= 0) {
            printf("INPUT ERROR\n");
            exit(0);
        }

        sum += n;
    }
    printf("%d\n", sum);
}
