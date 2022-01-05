#include <stdio.h>

// 전역 변수
int itemCnt = 0;
int money = 100;

/*
int result;

void buyItem(int cost, int cnt)
{
    if (money >= cost) {
        itemCnt += cnt;
        money -= cost;
        printf("아이템을 구매했습니다.\n");
        printf("  아이템 개수 : %d\n", itemCnt);
        printf("  잔액 : %d\n", money);
        result = 0;
    } else {
        printf("잔액이 부족합니다.\n");
        result = -1; // 실패를 나타낼 때 -1을 주로 사용
    }
}

int main()
{
    buyItem(3000, 5);

    // 중략

    if (result == -1) {
        printf("돈이 부족하시군요...\n");
    }

    buyItem(50, 7);
}
*/

/*
int buyItem(int cost, int cnt)
{
    if (money >= cost) {
        itemCnt += cnt;
        money -= cost;
        printf("아이템을 구매했습니다.\n");
        printf("  아이템 개수 : %d\n", itemCnt);
        printf("  잔액 : %d\n", money);
        return 0;
    } else {
        printf("잔액이 부족합니다.\n");
        return -1;
    }
}

int main()
{
    int result;
    result = buyItem(3000, 5);

    // 중략

    if (result == -1) {
        printf("돈이 부족하시군요...\n");
    }

    buyItem(50, 7);
}
*/

int buyItem(int cost, int cnt)
{
    if (money < cost) { // 이렇게 예외 처리를 해주면 else 문이 굳이 필요 없음
        printf("잔액이 부족합니다.\n");
        return -1;
    }

    itemCnt += cnt;
    money -= cost;
    printf("아이템을 구매했습니다.\n");
    printf("  아이템 개수 : %d\n", itemCnt);
    printf("  잔액 : %d\n", money);
    return 0;
}

int main()
{
    int result;

    result = buyItem(3000, 5);

    // 중략

    if (result == -1) {
        printf("돈이 부족하시군요...\n");
    }

    buyItem(50, 7);
}
