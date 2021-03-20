#include<stdio.h>
#include<math.h>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#define OK 0
#define DEGREES_FOR_TRANSLATE 180
#define FROM_FORMULES 4

int main()
{
    double alpha, square, a, b;


    printf("Input little side: ");
    scanf("%lf", &a);

    printf("Input big side: ");
    scanf("%lf", &b);

    printf("Input angle : ");
    scanf("%lf", &alpha);

    square = tan(alpha * M_PI / DEGREES_FOR_TRANSLATE) * fabs(b - a) * (b + a) / FROM_FORMULES;

    printf("Square is %.5lf", square);

    return OK;
}
