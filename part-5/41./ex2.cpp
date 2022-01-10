#include <stdio.h>

struct ProductInfo {
    int num;
    char name[100];
    int cost;
};

/*
// void productSale(ProductInfo p, int percent) // -> call-by-value
void productSale(ProductInfo& p, int percent) // -> call-by-reference
{
    p.cost -= p.cost * percent / 100;
}
*/

void productSale(ProductInfo* p, int percent) // -> call-by-reference
{
    p->cost -= p->cost * percent / 100;
}

int main()
{
    ProductInfo myProduct = { 4797283, "제주 한라봉", 20000 };

    /*
    myProduct.cost -= myProduct.cost * 10 / 100; // 할인가 = 원가 - (원가 * 할인율(%) / 100)
    */

    // productSale(myProduct, 10); // -> void productSale(ProductInfo& p, int percent) { }
    productSale(&myProduct, 10);

    printf("상품 번호 : %d\n", myProduct.num);
    printf("상품 이름 : %s\n", myProduct.name);
    printf("가     격 : %d\n", myProduct.cost);
}
