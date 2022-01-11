/*
2. 범위 기반 for 문을 사용하여 이차원 배열을 출력해 보세요.
*/

#include <iostream>

using namespace std;

int main()
{
    int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

    /*
    // 작성
    for (int row[] : arr) {
        for (int col : row) {
            cout << col << ' ';
        }
        cout << endl;
    }
    // -> 오류 뜸..
    */

    for (int(&ln)[3] : arr) {
        // 배열에 대한 참조(reference) 를 써야함 -> 배열 포인터와 선언 방식이 비슷
        for (int& col : ln) {
            cout << col << ' ';
        }
        cout << endl;
    }

    /*
    // 27강에서 다뤘었음
    for (int(*ln)[3] = arr; ln < arr + 2; ln++) {
        for (int* c = *ln; c < *ln + 3; c++) {
            cout << *c << ' ';
        }
        cout << endl;
    }
    */

    /*
    // 이렇게 그냥 auto 를 써도 됨
    for (auto& ln : arr) {
        for (auto& col : ln) {
            cout << col << ' ';
        }
        cout << endl;
    }
    */
}
