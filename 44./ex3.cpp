// enum

#include <stdio.h>

/*
const int GAMESTATE_MAINMENU = 0;
const int GAMESTATE_PLAYING = 1;
const int GAMESTATE_PAUSED = 2;
const int GAMESTATE_GAMEOVER = 3;

// 이렇게 상수로 선언해두면, 메모리 공간을 차지함
// 그리고, 새 값을 추가하거나 순서를 바꾸기가 불편함

// const int GAMESTATE_LOGO = 4; // 메인메뉴보다 앞쪽에 오는게 맞음 -> 순서 바꾸려면 값을 다 바꿔야함

int main()
{
    int currState = GAMESTATE_MAINMENU;

    while (true) {
        switch (currState) { // 상태가 늘어날수록 기억하기 힘들어짐
        // case 0:
        case GAMESTATE_MAINMENU:
            break;

        // case 1:
        case GAMESTATE_PLAYING:
            break;

        // case 2:
        case GAMESTATE_PAUSED:
            break;

        // case 3:
        case GAMESTATE_GAMEOVER:
            break;
        }
    }
}
*/

enum EGameState { // enum 선언 방식
    /*
    GAMESTATE_MAINMENU = 0,
    GAMESTATE_PLAYING = 1,
    GAMESTATE_PAUSED = 2,
    GAMESTATE_GAMEOVER = 3
    */
    /*
    // 아래처럼 선언해도, 자동으로 번호를 매겨줌
    GAMESTATE_MAINMENU, // == 0
    GAMESTATE_PLAYING,  // == 1
    GAMESTATE_PAUSED,   // == 2
    GAMESTATE_GAMEOVER  // == 3
    */
    // 중간에 값을 바꿔줄수도 있음
    GAMESTATE_MAINMENU,   // == 0
    GAMESTATE_PLAYING,    // == 1
    GAMESTATE_PAUSED = 4, // == 4
    GAMESTATE_GAMEOVER    // == 5
};

int main()
{
    // int currState = GAMESTATE_MAINMENU;
    EGameState currState = GAMESTATE_MAINMENU;
    // 이렇게 선언해도 됨 (enum 값을 저장한다는 것을 나타냄)

    while (true) {
        switch (currState) {
        case GAMESTATE_MAINMENU:
            break;

        case GAMESTATE_PLAYING:
            break;

        case GAMESTATE_PAUSED:
            break;

        case GAMESTATE_GAMEOVER:
            break;
        }
    }
}
