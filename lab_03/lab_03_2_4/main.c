#include<stdio.h>
#include<stdlib.h>

#define N 10
#define RIGHT_ELEMENT_INPUT 1
#define INPUT_ELEMENT_ERROR -1
#define INPUT_AMOUNT 2
#define NO_SUCH_ELEMENT -99999

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
        for (int j = 0; j < n; j++)
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


long find_max(long mat[][N], const int n, const int m)
{
    long max = -99999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i >= n - j) && (abs(mat[i][j] % 10) == 5) && (mat[i][j] > max))
            {
                max = mat[i][j];
            }
        }
    }
    return max;
}


int main()
{
    long mat[N][N], l, k;
    int n, m;

    setbuf(stdout, NULL);
    printf("Input size of matrix :\n");
    l = scanf("%d%d", &n, &m);

    if ((l != INPUT_AMOUNT) || (n <= 0) || (m <= 0) || (n != m))
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

    k = find_max(mat, n, m);

    if (k == NO_SUCH_ELEMENT)
    {
        printf("NO SUCH ELEMENT");
        return NO_SUCH_ELEMENT;
    }
    else
    {
        printf("\nNumber is :\n");
        printf("%ld", k);
    }
    return OK;
}