#include<stdio.h>

#define N 10
#define RIGHT_ELEMENT_INPUT 1
#define INPUT_ELEMENT_ERROR -1
#define INPUT_AMOUNT 2
#define UNRIGHT 0
#define RIGHT 1

#define INPUT_ERROR_AMOUNT 1
#define OK 0
#define UNRIGHT_ELEMENTS 2


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


long check_col(const int n, const int j, long mat[][N])
{
    long num;

    num = mat[0][j];
    for (int i = 1; i < n; i++)
    {
        num *= mat[i][j];

        if (num >= 0)
        {
            return UNRIGHT;
        }
        num /= mat[i - 1][j];
    }
    return RIGHT;
}


int fill_array(const int n, const int m, long mat[][N], long a[N])
{
    int k = 0;

    if (n == 1)
    {
        for (int j = 0; j < m; j++)
        {
            a[k] = 0;
            k += 1;
        }
        return k;
    }
    for (int j = 0; j < m; j++)
    {
        a[k] = check_col(n, j, mat);
        k += 1;
    }

    return k;
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
    long mat[N][N], l, a[N];
    int n, m, k;

    setbuf(stdout, NULL);
    printf("Input amount of rows and colums :\n");
    l = scanf("%d%d", &n, &m);

    if ((l != INPUT_AMOUNT) || (n <= 0) || (m <= 0))
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

    k = fill_array(n, m, mat, a);

    print_array(a, k);

    return OK;
}