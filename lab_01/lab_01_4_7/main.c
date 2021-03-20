#include<stdio.h>
#include<math.h>

#define INPUT_ERROR 1
#define OK 0
#define EROOR_X 2
#define ERROR_EPS 3
#define ITS_OK 2
#define EPS_CONST 1e-6

double func(double x)
{
    return (pow((1 + x), -3));
}

double solving(double x, double eps)
{
    int n;
    double s, s_next;
    s = 1;
    n = 2;
    s_next = (-1) * 0.5 * n * (n + 1) * x;

    while (fabs(s_next) > eps)
    {
        s += s_next;
        n = n + 1;
        s_next = s_next * (-(n + 1) * x / (n - 1));
    }

    return s;
}

void result(double x, double eps)
{
    double res_f, mis_abs, mis_otn, s;

    s = solving(x, eps);

    printf("\ns(x) = %.6f\n", s);
    res_f = func(x);
    printf("f(x) = %.6f\n", res_f);

    mis_abs = fabs(res_f - s);
    mis_otn = fabs(mis_abs / res_f);

    printf("Абсолютная ошибка %.6f\n", mis_abs);
    printf("Относительная ошибка %.6f", mis_otn);
}

int main()
{
    double x, eps;
    int count;
    x = eps = count = 0;
    setbuf(stdout, NULL);
    printf("Input x and eps : ");
    count = scanf("%lf%lf", &x, &eps);
    if (count != ITS_OK)
    {
        printf("Input error");
        return INPUT_ERROR;
    }

    if (fabs(x) >= 1)
    {
        printf("Unright input of X");
        return EROOR_X;
    }

    if (eps <= 0 || eps >= 1)
    {
        printf("Unright input of eps");
        return ERROR_EPS;
    }

    result(x, eps);

    return OK;
}