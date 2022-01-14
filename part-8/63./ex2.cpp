/*
1. 아래의 GameWindow 클래스의 코드에서 창 너비와 높이를 매개 변수로 받는 ResizeWindow 함수를 추가하여
다음 조건과 같이 width와 height의 값을 바꿀 수 있도록 하세요.
    - 들어온 매개 변수의 값과 일치하도록 창 크기를 설정할 것.
    - 너비가 800보다 작거나 높이가 600보다 작을 때는 각각 800, 600으로 설정할 것

2. GameWindow::GameWindow(int w, int h) 생성자도 마찬가지로 2번의 조건을 만족하도록 수정하세요.

3. 작성한 코드에서 상수화가 가능한 부분을 모두 상수화하세요.
*/

#include <iostream>

using namespace std;

/*
class GameWindow {
public:
    GameWindow();
    GameWindow(int, int);

    int GetWidth();
    int GetHeight();

private:
    int width;
    int height;
};

GameWindow::GameWindow()
    : width(800)
    , height(600)
{
}
GameWindow::GameWindow(int w, int h)
    : width(w)
    , height(h)
{
}

int GameWindow::GetWidth() { return width; }
int GameWindow::GetHeight() { return height; }
*/

/*
class GameWindow {
public:
    GameWindow();
    GameWindow(const int, const int);

    int GetWidth() const;
    int GetHeight() const;

    void ResizeWindow(const int, const int);

private:
    int width;
    int height;
};

GameWindow::GameWindow()
    : width(800)
    , height(600)
{
}
GameWindow::GameWindow(const int w, const int h)
    : width(w > 800 ? w : 800)
    , height(h > 600 ? h : 600)
{
}

int GameWindow::GetWidth() const { return width; }
int GameWindow::GetHeight() const { return height; }

void GameWindow::ResizeWindow(const int w, const int h)
{
    width = w > 800 ? w : 800;
    height = h > 600 ? h : 600;
};
*/

class GameWindow {
public:
    GameWindow();
    GameWindow(const int, const int); // 생성자는 상수형 메서드로 바꿀 수 없음 (const 를 못 붙임)

    int GetWidth() const;
    int GetHeight() const;

    void ResizeWindow(const int, const int); // 멤버 변수의 값을 바꾸는 함수이므로, 상수형 메서드로 바꾸면 안 됨

private:
    int width;
    int height;
};

GameWindow::GameWindow()
    : width(800)
    , height(600)
{
}
GameWindow::GameWindow(const int w, const int h)
{
    /*
    if (w < 800)
        width = 800;
    else
        width = w;
    if (h < 600)
        height = 600;
    else
        height = h;
    */
    // 이렇게 중복된 코드가 있으면 나중에 작업하기 번거로워질 수 있음
    // -> 800, 600이라는 최소 크기를 다른 값으로 바꾸려는 경우를 예로 들 수 있음
    // -> 이렇게, 코드를 복사/붙여넣기 하는 것은 그렇게 좋지 않음
    // -> 생성자와 ResizeWindow 의 역할이 같으므로, 그냥 ResizeWindow 메서드를 호출하면 됨

    ResizeWindow(w, h);
}

int GameWindow::GetWidth() const { return width; }
int GameWindow::GetHeight() const { return height; }

void GameWindow::ResizeWindow(const int w, const int h)
{
    /*
    if (w < 800)
        width = 800;
    else
        width = w;
    if (h < 600)
        height = 600;
    else
        height = h;
    */
    // 둘 중 아무거나 상관 없음
    if (w >= 800)
        width = w;
    else
        width = 800;
    if (h >= 600)
        height = h;
    else
        height = 600;
}

int main()
{
    /*
    GameWindow mainWindow;
    mainWindow.ResizeWindow(1366, 768);
    */
    GameWindow mainWindow(500, 768);
    cout << mainWindow.GetWidth() << "x" << mainWindow.GetHeight() << endl;
}
