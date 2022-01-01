/*
2. 체중(kg, 실수)과 키(m, 실수)를 입력받아서 체질량 지수를 구하는 프로그램을 만들어 보세요.
*/

#include <stdio.h>

int main()
{
    /*
    float weight, height;

    scanf("%f%f", &weight, &height);

    printf("%f\n", weight / (height * height));
    */

    float weight;
    float height;

    printf("체중 입력 (kg) : ");
    scanf("%f", &weight);
    printf("키 입력 (m) : ");
    scanf("%f", &height);

    // t의 제곱 = t * t
    float bmi = weight / (height * height);

    printf("BMI : %f\n", bmi);
}
