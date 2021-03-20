#include<stdio.h>

#define N 1000

#define NOT_UNIQ 1
#define UNIQ 0
#define OK 0
#define DELETE 10000
#define EMPTY 0
#define ARRAY_IS_EMPTY 1

int read_array(unsigned int *a)
{
    int k, n = 0;
    for (int i = 0; i < N; i++)
    {
        k = scanf("%u", &a[i]);

        if (k == EOF)
        {
            break;
        }
        n++;
    }
    return n;
}


int unique_num(unsigned int *a, const int n, const int i)
{
    unsigned int num;

    num = a[i];
    for (int j = 0; j < n; j++)
    {
        if ((num == a[j]) && (i != j))
        {
            return NOT_UNIQ;
        }
    }
    return UNIQ;
}


unsigned int summary(unsigned int *a, const int n)
{
    unsigned int sum = 0;
    int check;
    for (int i = 0; i < n; i++)
    {
        check = unique_num(a, n, i);

        if ((check == UNIQ) && (a[i] != DELETE))
        {
            sum += a[i];
        }
    }
    return sum;
}

void change_array(unsigned int *a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((a[i] == a[j]) && (i != j))
            {
                a[j] = DELETE;
            }
        }
    }
}


int main()
{
    unsigned int a[N];
    int n;

    n = read_array(a);

    if (n == EMPTY)
    {
        return ARRAY_IS_EMPTY;
    }

    change_array(a, n);

    printf("%u", summary(a, n));

    return OK;
}