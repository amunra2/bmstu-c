#include<stdio.h>
#include<math.h>

#define INPUT_ERROR 1
#define OK 0
#define POINT_ERROR 2
#define ITS_OK 6
#define EPS 1e-6
#define COORD(a, b) (b - a)


double scalar(double xa, double x1, double ya, double y1, double x2, double y2)
{
    return (COORD(xa, x1) * COORD(xa, x2) + COORD(ya, y1) * COORD(ya, y2));
}

double pseudoscalar(double xa, double x1, double ya, double y1, double x2, double y2)
{
    return (COORD(x1, x2) * COORD(y1, ya) - COORD(y1, y2) * COORD(x1, xa));
}

void solving(double xa, double x1, double ya, double y1, double x2, double y2)
{
    double scalar_power, pseudoscalar_power;

    // AP1 and  AP2

    scalar_power = scalar(xa, x1, ya, y1, x2, y2);

    // P1P2 and P1A

    pseudoscalar_power = pseudoscalar(xa, x1, ya, y1, x2, y2);


    if (scalar_power <= 0 && fabs(pseudoscalar_power) < EPS)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}

int main()
{
    double x1, y1, x2, y2, xa, ya;
    int count;

    x1 = x2 = y1 = y2 = 0;

    printf("Input COORDs and point A: ");
    count = scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &xa, &ya);

    if (count != ITS_OK)
    {
        printf("Input error");
        return INPUT_ERROR;
    }
    else if ((fabs(x1 - x2) < EPS) && (fabs(y1 - y2) < EPS))
    {
        printf("Error : it's a point");
        return POINT_ERROR;
    }

    solving(xa, x1, ya, y1, x2, y2);
    return OK;
}
