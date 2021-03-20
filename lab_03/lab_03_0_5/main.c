#include<stdio.h>

#define N 10
#define RIGHT_ELEMENT_INPUT 1
#define INPUT_ELEMENT_ERROR -1
#define INPUT_AMOUNT 2
#define UNRIGHT 0
#define RIGHT 1
#define NO_PRIME_ELEMENTS -1

#define INPUT_ERROR_AMOUNT 1
#define OK 0
#define UNRIGHT_ELEMENTS 2
#define TASK_MISTAKE 3
#define NO_PRIME_ELEMENTS_ERROR 4


long read_matrix(const int n, const int m, long mat[][N])
{
    int r;
    printf("\nInput matrix :\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            r = scanf("%ld", &mat[i][j]);

            if (r != RIGHT_ELEMENT_INPUT)
            {
                return INPUT_ELEMENT_ERROR;
            }
        }
    }
    return RIGHT_ELEMENT_INPUT;
}


long check_num(const long num)
{
    if (num == 1)
    {
        return UNRIGHT;
    }

    int k = 2;
    while (k < num)
    {
        if (num % k == 0)
        {
            return UNRIGHT;
        }
        k++;
    }
    return RIGHT;
}


void reverse_array(long *const a, const int n)
{
    int current;
    for (int i = 0; i < (n / 2); i++)
    {
        current = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = current;
    }
}


int change_elements(long mat[][N], const int n, const int m, long *const a)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check_num(mat[i][j]) == RIGHT)
            {
                a[k] = mat[i][j];
                k++;
            }
        }
    }

    if (k == 0)
    {
        return NO_PRIME_ELEMENTS;
    }

    reverse_array(a, k);

    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check_num(mat[i][j]) == RIGHT)
            {
                mat[i][j] = a[k];
                k++;
            }
        }
    }

    return OK;
}


void print_matrix(long mat[][N], const int n, const int m)
{
    printf("\n\nNew matrix :\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%ld ", mat[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    long mat[N][N], l, a[N * N];
    int n, m;

    setbuf(stdout, NULL);
    printf("Input amount of rows and colums :\n");
    l = scanf("%d%d", &n, &m);

    if (l != INPUT_AMOUNT)
    {
        printf("INPUT ERROR AMOUNT");
        return INPUT_ERROR_AMOUNT;
    }

    l = read_matrix(n, m, mat);

    if (l == INPUT_ELEMENT_ERROR)
    {
        printf("INPUT ERROR ELEMENTS");
        return UNRIGHT_ELEMENTS;
    } 

    l = change_elements(mat, n, m, a);

    if (l == NO_PRIME_ELEMENTS)
    {
        printf("NO PRIME ELEMENTS");
        return NO_PRIME_ELEMENTS_ERROR;
    }

    print_matrix(mat, n, m);

    return OK;
}