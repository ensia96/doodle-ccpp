// 범위 기반 for 문
// 배열에 대해, for 문을 더 편하게 사용할 수 있음

#include <iostream>

using namespace std;

int main()
{
    int arr[10] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };

    /*
    for (int i = 0; i < 10; i++) { // i = index, i 번째 인덱스에 있는 원소
        cout << arr[i] << endl;
    }
    */

    /*
    for (int n : arr) { // arr 안에 있는 모든 요소를 n에 대입
        cout << n << ' ';
        n++; // n의 값을 바꿔도 배열의 값은 바뀌지 않음
             // 내부적으로는 int n = arr[i]; 처럼 동작하기 때문
    }
    cout << endl;

    for (int n : arr) {
        cout << n << ' ';
    }
    cout << endl;
    */

    for (int& n : arr) { // 참조 (reference) 변수이기 때문에 값이 실제로도 바뀜
        cout << n << ' ';
        n++;
    }
    cout << endl;

    for (int n : arr) {
        cout << n << ' ';
    }
    cout << endl;
}
