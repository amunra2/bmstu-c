#include<stdio.h>
#include<math.h>

#define INPUT_ERROR_ARRAY 2
#define INPUT_ERROR_AMMOUNT 1

#define OK 0
#define N 10
#define INPUT_AMMOUNT 1

long read_array(long *const a, const long n)
{
    long k = 0;
    printf("Input array :\n");

    for (int i = 0; i < n; i++)
    {
        k += scanf("%ld", &a[i]);
    }

    return k;
}

void insertion_sort(long *const a, const long n)
{
    long current;
    for (int i = 0; i < n; i++)
    {
        current = a[i];
        int j = i;
        while ((a[j - 1] > current) && (j > 0))
        {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = current;
    }
}

void print_array(const long *a, const long n)
{
    printf("New array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%ld ", a[i]);
    }
}


int main()
{
    long n, a[N], k, l;

    setbuf(stdout, NULL);
    printf("Input ammount of elements :\n");
    l = scanf("%ld", &n);
    if ((l != INPUT_AMMOUNT) || (n == 0))
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

    insertion_sort(a, n);

    print_array(a, n);
    return OK;
}