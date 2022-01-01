// switch

#include <stdio.h>

int main()
{
    int choice;

makeChoice:

    printf("새 게임 : 1\n");
    printf("불러오기 : 2\n");
    printf("설정 : 3\n");
    printf("크레딧 : 4\n");

    scanf("%d", &choice);

    /*
    if (choice == 1) {
        printf("새 게임.\n");
    } else if (choice == 2) {
        printf("불러오기.\n");
    } else if (choice == 3) {
        printf("설정.\n");
    } else if (choice == 4) {
        printf("크레딧.\n");
    } else {
        printf("잘못 입력하셨습니다.\n");
    }
    */

    switch (choice) {
    case 1:
        printf("새 게임.\n");
        break; // <- 중괄호 밖으로 바로 나감

    case 2:
        printf("불러오기.\n");
        break;

    case 3:
        printf("설정.\n");
        break;

    case 4:
        printf("크레딧.\n");
        break;

    default:
        printf("잘못 입력하셨습니다.\n");
        // goto = go to -> ~로 가라.
        // goto 문을 사용하면 스파게티 코드가 될 가능성이 있음..
        // 가끔 유용할 때가 있지만, 굳이 쓰지 않는 것이 더 나음..
        goto makeChoice;
        break;
    }
}
