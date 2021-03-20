#include<stdio.h>
#include<math.h>
#define OK 0

int main()
{
    float v1, t1, v2, t2, t;

    printf("Input v1: ");
    scanf("%f", &v1);

    printf("Input t1: ");
    scanf("%f", &t1);

    printf("Input v2: ");
    scanf("%f", &v2);

    printf("Input t2: ");
    scanf("%f", &t2);

    t = (t1 * v1 + t2 * v2) / (v1 + v2);

    printf("V is %.5f\n", v1 + v2);
    printf("t is %.5f", t);

    return OK;
}
