#include<stdio.h>
#include<math.h>

#define INPUT_ERROR_ARRAY 3
#define INPUT_ERROR_AMMOUNT 2
#define RIGHT_NUMBER 0
#define UNRIGHT_NUMBER 1
#define NO_RIGHT_ELEMENTS_ERROR 1

#define OK 0
#define EPS 1e-6
#define N 10
#define INPUT_AMMOUNT 1
#define NO_RIGHT_ELEMENTS 0

int read_array(long *const a, const int n)
{
    int k = 0;
    printf("Input array :\n");

    for (int i = 0; i < n; i++)
    {
        k += scanf("%ld", &a[i]);
    }

    return k;
}

long check_num(const long num)
{
    double d;
    d = sqrt(num);
    while (d >= 1)
    {
        d--;
    }
    if (d < EPS)
    {
        return RIGHT_NUMBER;
    }
    else
    {
        return UNRIGHT_NUMBER;
    }
}

void change_num(long *a, int j, int n)
{
    while (j < n)
    {
        a[j] = a[j + 1];
        j++;
    }
}

int new_mas(long *const a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (check_num(a[i]) == RIGHT_NUMBER)
        {
            int j = i;
            change_num(a, j, n);
            n--;
            i--;
        }
    }
    return n;
}

void print_array(const long *a, const int n)
{
    printf("New array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%ld ", a[i]);
    }
}


int main()
{
    long a[N], k, l;
    int n;

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

    k = new_mas(a, n);

    if (k == NO_RIGHT_ELEMENTS)
    {
        printf("NO RIGHT ELEMENTS");
        return NO_RIGHT_ELEMENTS_ERROR;
    }
    print_array(a, k);
    return OK;
}