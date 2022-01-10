// 구조체 포인터

#include <stdio.h>

struct ProductInfo {
    int num;
    char name[100];
    int cost;
};

int main()
{
    ProductInfo myProduct = { 4797283, "제주 한라봉", 20000 };

    ProductInfo* ptr_product = &myProduct;

    /*
    // *ptr_product.num == *(ptr_product.num)
    printf("상품 번호 : %d\n", (*ptr_product).num);
    printf("상품 이름 : %s\n", (*ptr_product).name);
    printf("가     격 : %d\n", (*ptr_product).cost);
    */

    // C 언어에서 제공하는 연산자 : (구조체 포인터)->(멤버 변수 이름)
    printf("상품 번호 : %d\n", ptr_product->num); // == (*ptr_product).num
    printf("상품 이름 : %s\n", ptr_product->name);
    printf("가     격 : %d\n", ptr_product->cost);

    // (*a).b == a->b
}
