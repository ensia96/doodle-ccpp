// default parameter : 기본 값이 있는 매개 변수

#include <iostream>

using namespace std;

int inventory[64] = { 0 }; // inventory[i] == 현재 보유 중인 i번 아이템의 개수
int score = 0;

/*
void getItem(int itemId)
{
    inventory[itemId]++;
}

void getItem(int itemId, int cnt) // 이렇게, 매개 변수의 개수에 따라서도 구분이 됨 -> 이것도 함수 오버로딩
{
    inventory[itemId] += cnt;
}

void getItem(int itemId, int cnt, int sc)
{
    inventory[itemId] += cnt;
    score += sc;
}
*/

// 위처럼 매개 변수가 추가되는 식이면, 일부 매개 변수에 기본 값을 주는 방법도 있음
// -> default parameter : 값이 주어지지 않으면 지정된 기본 값으로 대체

void getItem(int itemId, int cnt = 1, int sc = 0)
// 아이템 개수가 따로 주어지지 않으면 인벤토리에 아이템 1개가 추가되도록
// 점수가 따로 주어지지 않으면 0점을 추가하도록 -> 점수 변화 없음

// void getItem(int itemId, int cnt = 1, int sc = 0, int a) // 이런 식으로는 안 됨
// -> 인자가 여러 개 주어지면, 어떤 인자가 어떤 매개 변수에 들어가야 하는지 모호해지기 때문
// -> 그래서, '기본 값이 있는 매개 변수는 오른쪽에 적는다.' 라는 규칙이 생김
{
    inventory[itemId] += cnt;
    score += sc;
}

int main()
{
    getItem(6, 5); // == getItem(6 ,5, 0);
    getItem(3, 2); // == getItem(3, 2, 0);
    getItem(3);    // == getItem(3, 1, 0);
    getItem(11, 34, 7000);

    cout << score << endl;
    for (int i = 0; i < 16; i++) {
        cout << inventory[i] << ' ';
    }
    cout << endl;
}
