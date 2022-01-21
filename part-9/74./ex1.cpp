#include <iostream>

using namespace std;

struct Point {
    int x, y;
};

class Polygon {
public:
    Polygon()
    {
        nPoints = 0;
        points = NULL;
    }
    Polygon(const int nPoints, const Point* points)
        : nPoints(nPoints)
    {
        this->points = new Point[nPoints];
        for (int i = 0; i < nPoints; i++) {
            this->points[i] = points[i];
        }
    }

    /*
    // 복사 생성자 구현
    Polygon(const Polygon& P)
    {
        nPoints = P.nPoints;
        points = new Point[nPoints];
        for (int i = 0; i < nPoints; i++) {
            points[i] = P.points[i];
        }
    }
    */
    Polygon(const Polygon& rhs)
    {
        nPoints = rhs.nPoints;
        points = new Point[nPoints];
        for (int i = 0; i < nPoints; i++) {
            points[i] = rhs.points[i];
        }
        cout << "깊은 복사" << endl;
    }

    /*
    // 이동 생성자 구현
    Polygon(Polygon&& P)
    {
        nPoints = P.nPoints;
        points = P.points;
        P.points = NULL;
    }
    */
    Polygon(Polygon&& rhs)
    {
        nPoints = rhs.nPoints;
        points = rhs.points;
        rhs.points = NULL;
        cout << "얕은 복사" << endl;
    }

    ~Polygon()
    {
        delete[] points;
    }

    /*
    // 복사 대입 연산자 구현
    Polygon operator=(const Polygon& P)
    {
        nPoints = P.nPoints;
        points = new Point[nPoints];
        for (int i = 0; i < nPoints; i++) {
            points[i] = P.points[i];
        }
        return *this;
    }
    // 대입 연산자는 따로 더 복습해봐야 할 듯..
    // -> 한 번 배우고 바로 구현하는게 쉬운 편은 아니라고 함 (졌잘싸..)
    // -> 객체 참조를 반환하도록 선언, 자기 자신이 대입되는 경우 처리, 사용 중이던 공간이 있을 수 있으니 할당 해제
    */
    Polygon& operator=(const Polygon& rhs)
    {
        if (this != &rhs) {
            nPoints = rhs.nPoints;
            delete[] points;
            points = new Point[nPoints];
            for (int i = 0; i < nPoints; i++) {
                points[i] = rhs.points[i];
            }
        }

        cout << "깊은 복사" << endl;
        return *this;
    }

    /*
    // 이동 대입 연산자 구현
    Polygon operator=(Polygon&& P)
    {
        nPoints = P.nPoints;
        points = P.points;
        P.points = NULL;
        return *this;
    }
    */
    Polygon& operator=(Polygon&& rhs)
    {
        if (this != &rhs) {
            // 지난 수업에서 설명이 누락됨 (이미 동적으로 할당받은 공간이 있는 상황)
            // -> 이동 대입 연산에서도, 복사 대입 연산과 마찬가지로, 사용 중이던 공간이 있는지부터 확인해야 함
            // -> 만약 사용 중이던 공간이 있었다면, 자기 자신이 r-value 로 들어왔는지도 확인해줘야 함
            // -> 마이크로 소프트 공식 문서에도 이런 식으로 구현한다고 나와 있음
            // -> 이해하기 어려운 부분이기 때문에 복습을 많이 하길 권장함
            nPoints = rhs.nPoints;
            delete[] points;
            points = rhs.points;
            rhs.points = NULL;
        }
        cout << "얕은 복사" << endl;
        return *this;
    }

    int GetNPoints() const
    {
        return nPoints;
    }

    Point* GetPoints() const
    {
        if (nPoints == 0)
            return NULL;
        return points;
    }

private:
    int nPoints;
    Point* points;
};

Polygon getSquare()
{
    Point points[4] = { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } };
    Polygon p(4, points);
    return p;
}

int main()
{
    Polygon a;
    a = getSquare(); // 얕은 객체 복사 2회
    Polygon b = a;   // 깊은 객체 복사 1회
    Polygon c;
    c = a; // 깊은 객체 복사 1회

    int nPoints = c.GetNPoints();
    Point* points = c.GetPoints();
    for (int i = 0; i < nPoints; i++) {
        cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
    }
}

// 묵시적 형 변환은 나중에 다시 배울 예정 -> 이번 파트에서는 연습문제 풀이 x
