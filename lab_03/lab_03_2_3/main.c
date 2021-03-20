#include<stdio.h>

#define N 10
#define RIGHT_ELEMENT_INPUT 1
#define INPUT_ELEMENT_ERROR -1
#define INPUT_AMOUNT 2


#define INPUT_ERROR_AMOUNT 1
#define OK 0
#define UNRIGHT_ELEMENTS 2
#define TASK_MISTAKE 3

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



void swap_rows(long mat[][N], const int k, const int current, const int m)
{
    long change;
    for (int j = 0; j < m; j++)
    {
        change = mat[k][j];
        mat[k][j] = mat[current][j];
        mat[current][j] = change;
    }
}

long power_row(long mat[][N], const int current, const int m)
{
    long power = 1;
    for (int j = 0; j < m; j++)
    {
        power *= mat[current][j];
    }
    return power;
}


void sort_matrix(long mat[][N], const int n, const int m)
{
    for (int q = 0; q < n; q++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (power_row(mat, i, m) > power_row(mat, i + 1, m))
            {
                swap_rows(mat, i, i + 1, m);
            }
        }
    }
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
    long mat[N][N], l;
    int n, m;

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

    sort_matrix(mat, n, m);

    print_matrix(mat, n, m);

    return OK;
}






