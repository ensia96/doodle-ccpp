// 배열의 동적 할당
// -> 일반적인 자료들보다는 배열을 동적 할당하는 경우가 더 많음
// -> int arr[1000]; 의 경우, 최대 1000칸을 사용할 수 있음
// -> 1000칸을 사용할 수도 있다라는 이유만으로 공간을 미리 넉넉하게 할당해두는 것
// -> 상황에 따라서는 1칸만 사용할 수도 있기 때문에, 메모리 공간이 비교적 많이 낭비되는 편임
// -> 사용할 만큼만 공간을 할당할 방법이 있다면 아주 좋을 것임
// -> 이런 상황은 동적 할당을 통해 해결할 수 있음

#include <iostream>

using namespace std;

int main()
{
    int* arr;
    int len;

    cout << "동적할당할 배열 길이 입력 : ";
    cin >> len;

    arr = new int[len]; // new int[len] == len 만큼의 크기를 갖는 int 형 배열을 생성한 후, 배열이 시작되는 위치의 주소를 반환
                        // arr = &arr[0] 이므로, arr 포인터 자체를 배열처럼 사용할 수 있음
                        // -> 원하는 크기만큼의 공간을 할당받을 수 있음 => 동적 할당

    for (int i = 0; i < len; i++) {
        arr[i] = len - i;
    }
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }

    /*
    delete arr; // 변수와 마찬가지로 할당 해제해줘야함
                // -> 이렇게만 적어두면 문제가 생김
                // -> arr 은 int 형 자료를 가리키는 포인터이기 때문
                // -> ex1 에서와 마찬가지로 int 형 자료 하나가 저장된 공간만큼만 할당 해제됨
    */
    delete[] arr; // 때문에 이런 식으로 작성해줘야 함
                  // 동적으로 할당된 모든 공간을 알아서 할당 해제해줌
}