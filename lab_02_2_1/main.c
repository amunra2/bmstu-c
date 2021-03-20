#include<stdio.h>
#include<math.h>

#define INPUT_ERROR_ARRAY 2
#define INPUT_ERROR_AMMOUNT 1
#define NO_NEGATIVE_ELEMENTS 3

#define OK 0
#define EPS 1e-6
#define N 10
#define INPUT_AMMOUNT 1


int read_array(int *const a, const int n)
{
    int k = 0;
    printf("Input array :\n");

    for (int i = 0; i < n; i++)
    {
        k += scanf("%d", &a[i]);
    }

    return k;
}


double solve_arif(const int *a, const int n)
{
    int k = 0;
    double result, sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            sum += a[i];
            k++;
        }
    }
    if (k == 0)
    {
        return k;
    }
    else
    {
        result = sum / k;
        return result;
    }
}


int main()
{
    int n, a[N], k, l;
    double res;
    setbuf(stdout, NULL);
    printf("Input ammount of elements :\n");
    l = scanf("%d", &n);
    if (l != INPUT_AMMOUNT)
    {
        printf("INPUT ERROR AMMOUNT");
        return INPUT_ERROR_AMMOUNT;
    }

    k = read_array(a, n);

    if (k != n)
    {
        printf("INPUT ERROR ARRAY");
        return INPUT_ERROR_ARRAY;
    }

    res = solve_arif(a, n);

    if (fabs(res) < EPS)
    {
        printf("NO NEGATIVE ELEMENTS");
        return NO_NEGATIVE_ELEMENTS;
    }
    else
    {
        printf("Result is %.4lf", res);

        return OK;
    }
}