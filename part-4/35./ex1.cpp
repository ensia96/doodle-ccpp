// 재귀 함수 : 자기 자신의 정의 속에 자기 자신을 포함함
// 학교 (배울 학, 학교(배울 햑, 학교(...) 교) 교)
// 재귀 = recursion

#include <stdio.h>

/*
void rec() // 아래 동작을 무한히 반복함 -> 실행은 되지만 결국엔 에러 발생
{
    printf("***\n");
    rec();
}
*/

/*
void rec(int n)
{
    printf("n = %d\n", n);
    rec(n + 1); // 현재 n에 대한 작업이 끝나기 전에 다시 자기 자신을 호출 -> 무한 반복
}
*/

void rec(int n)
{
    if (n > 5) // 종결 조건 -> n이 5보다 커지면 종료 -> 6이 될 때
        return;
    printf("n = %d\n", n);
    rec(n + 1); // n이 5인 함수 실행부터 차례대로 이 동작을 마무리
}

int main()
{
    rec(1);
}
