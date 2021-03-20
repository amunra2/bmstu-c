#include<stdio.h>

#define INPUT_ERROR_ARRAY 3
#define INPUT_ERROR_AMMOUNT 2
#define RIGHT_NUMBER 0
#define UNRIGHT_NUMBER 1
#define NO_RIGHT_ELEMENTS_IN_ARRAY 1

#define OK 0
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

long check_num(long num)
{
    long first, last;
    if (num < 0)
    {
        num *= -1;
    }
    first = num % 10;
    while (num > 9)
    {
        num /= 10;
    }
    last = num;
    if (last == first)
    {
        return RIGHT_NUMBER;
    }
    else
    {
        return UNRIGHT_NUMBER;
    }
}

int new_mas(const long *a, const int n, long *const b)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (check_num(a[i]) == RIGHT_NUMBER)
        {
            b[j] = a[i]; 
            j++;
        }
    }
    return j;
}

void print_array(const long *b, const int n)
{
    printf("New array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%ld ", b[i]);
    }
}


int main()
{
    long a[N], k, l, b[N];
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
    k = new_mas(a, n, b);
    if (k == NO_RIGHT_ELEMENTS)
    {
        printf("NO RIGHT ELEMENTS");
        return NO_RIGHT_ELEMENTS_IN_ARRAY;
    }
    print_array(b, k);
    return OK;
}