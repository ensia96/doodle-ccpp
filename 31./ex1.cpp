#include <stdio.h>

/*
int main() // 함수 정의(생성)
{
    printf("Hello, World!\n"); // 함수 호출 (사용)
    // printf() 함수는 stdio.h 파일에 정의되어 있음
}
*/

/*
int main()
{
    int itemCnt = 0;
    int money = 100;

    // 아이템을 산다.
    itemCnt++;
    money -= 20;
    printf("아이템을 구매했습니다.\n");
    printf("  아이템 개수 : %d\n", itemCnt);
    printf("  잔액 : %d\n", money);

    // 중략

    // 아이템을 산다.
    itemCnt++;
    money -= 10;
    printf("아이템을 구매했습니다.\n");
    printf("  아이템 개수 : %d\n", itemCnt);
    printf("  잔액 : %d\n", money);
    // 위와 같은 여러 줄의 코드를 묶어서 함수로 만들 수 있음
}
*/

// 전역 변수
int itemCnt = 0;
int money = 100;
// 여러 함수에서 사용하기 위해, 변수를 밖에서(전역으로) 선언

/*
void buyItem() // 역할을 잘 나타낼 수 있는 이름으로 지정해야 함
{
    // 아이템을 산다.
    itemCnt++;
    money -= 20;
    printf("아이템을 구매했습니다.\n");
    printf("  아이템 개수 : %d\n", itemCnt);
    printf("  잔액 : %d\n", money);
}

int main()
{
    // int a; // 지역 변수
    buyItem();

    // 중략

    buyItem();
}
*/

/*
int cost;

void buyItem()
{
    // 아이템을 산다.
    itemCnt++;
    money -= cost;
    printf("아이템을 구매했습니다.\n");
    printf("  아이템 개수 : %d\n", itemCnt);
    printf("  잔액 : %d\n", money);
}

int main()
{
    cost = 30;
    buyItem(); // money - 30

    // 중략

    cost = 50;
    buyItem(); // money - 50
}
*/

/*
void buyItem(int cost) // 매개 변수도 지역변수 -> main 함수에선 사용할 수 없음
                       // 매개 변수 여러 개도 가능
{
    // 아이템을 산다.
    itemCnt++;
    money -= cost;
    printf("아이템을 구매했습니다.\n");
    printf("  아이템 개수 : %d\n", itemCnt);
    printf("  잔액 : %d\n", money);
}
*/

void buyItem(int cost, int cnt)
{
    // 아이템을 산다.
    itemCnt += cnt;
    money -= cost;
    printf("아이템을 구매했습니다.\n");
    printf("  아이템 개수 : %d\n", itemCnt);
    printf("  잔액 : %d\n", money);
}

int main()
{
    buyItem(30, 5); // money - 30

    // 중략

    buyItem(50, 7); // money - 50
}
