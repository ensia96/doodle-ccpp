#include <stdio.h>

/*
struct Point {
    // int x, y;
    int x;
    int y; // 따로 선언해도 됨
    char c;
    double d;
    // 여러 자료형을 포함하도록 선언할 수 있음
    // 주소록처럼 생각할 수 있음(이름, 전화번호, 이메일 , ...)
    // 쇼핑몰 상품처럼 생각할 수도 있음(이름 : 한라봉, 가격 : 00원, ...)
};
*/

struct ProductInfo {
    int num;        // 4바이트
    char name[100]; // 100바이트
    int cost;       // 4바이트
};

int main()
{
    /*
    ProductInfo myProduct;

    myProduct.num = 218712;
    */

    ProductInfo myProduct = { 4797283, "제주 한라봉", 19900 };

    /*
    printf("상품 번호 : %d\n", myProduct.num);
    printf("상품 이름 : %s\n", myProduct.name);
    printf("가     격 : %d원\n", myProduct.cost);

    printf("sizeof(myProduct) = %d\n", sizeof(myProduct));
    */

    printf("상품 번호 : %d\n", &myProduct.num);
    printf("상품 이름 : %d\n", myProduct.name);
    printf("가     격 : %d\n", &myProduct.cost);
    // 선언된 순서대로 메모리상에 나란히 붙어서 저장됨
    // 구조체의 주소 == 첫 번째 자료의 시작 주소

    printf("%d\n", &myProduct);
}
