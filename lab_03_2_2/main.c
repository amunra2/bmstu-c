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


void insert_row(long mat[][N], const int n, const int m, const int row)
{
    long rem, current;
    for (int j = 0; j < m; j++)
    {	
        rem = mat[row][j];
        mat[row][j] = -1;
        for (int i = row + 1; i < n + 1; i++)
        {
            current = mat[i][j];
            mat[i][j] = rem;
            rem = current;
        }
    }
}


int sum_of_digits(long num)
{
    int k = 0;

    if (num < 0)
    {
        num *= -1;
    }
    while (num > 9)
    {
        k += num % 10;
        num /= 10;
    }	
    k += num;
    return k;
}


int check_row(long mat[][N], const int row, const int m)
{
    long num = 0;
    for (int j = 0; j < m; j++)
    {
        if (sum_of_digits(mat[row][j]) % 2 != 0)
        {
            num += 1;
        }
    }

    if (num >= 2)
    {
        return RIGHT;
    }
    else
    {
        return UNRIGHT;
    }
}


int check_matrix(long mat[][N], const int n, const int m)
{
    int check, k = n;
    for (int i = 0; i < k; i++)
    {
        check = check_row(mat, i, m);

        if (check == RIGHT)
        {
            insert_row(mat, k, m, i);
            k += 1;
            i++;
        }
    }
    return k;
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

    k = check_matrix(mat, n, m);

    print_matrix(mat, k, m);

    return OK;
}