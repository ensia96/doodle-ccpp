/*
3. 다음과 같은 함수 정의에서 컴파일 오류가 나는 이유를 찾아보세요.
*/

//컴퓨터에서 직사각형을 그리는 방법
void drawRectangle(int l, int r, int t, int b) // -> 왼쪽, 오른쪽 변의 x 좌표, 위쪽, 아래쪽 변의 y 좌표
{
}

/*
void drawRectangle(int x = 0, int y = 0, int w, int h) // -> 시작점의 좌표와 너비와 높이
// 기본 값이 있는 매개 변수가 왼쪽에 위치하기 때문
{
}
*/

/*
void drawRectangle(int w, int h, int x = 0, int y = 0) // 이렇게 바꿔주면 또 다른 문제가 발생함
// 위에 있는 함수와 매개 변수의 개수가 같기 때문에, 위에 있는 함수를 사용할 수 없게 됨
{
}
*/

int main()
{
    drawRectangle(0, 0, 0, 0);
}
