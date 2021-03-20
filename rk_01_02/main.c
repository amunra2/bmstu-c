#include<stdio.h>

#define N 10

void zero_b(int b[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            b[i][j] = 0;
        }
    }
}


int create_b(int b[][N])
{
	int num, k, rows = 0;
    for (int i = 0; i < N; i++)
    {
    	int j = 0;
        k = scanf("%d", &num);

        if (k == EOF)
        {
        	break;
        }
        rows += 1;

        while (num > 9)
        {
        	b[i][N - j - 1] = num % 10;
        	num /= 10;
        	j++;
        }

        b[i][N - j - 1] = num;
    }
    return rows;
}


int max_number(int b[][N], const int n)
{
    int max = -9999, row;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if((b[i][j] > max) && (b[i][j] != 0))
            {
            	max = b[i][j];
            	row = i;
            }
        }
    }
    return (row + 1);
}

void print_matrix(int b[][N], const int n, const int row)
{
	printf("Max row number is %d", row);
	printf("%d %d %d \n", n, 1, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (b[i][j] != 0)
            {
            	printf("%d %d %d \n", i + 1, N - j, b[i][j]);
            }
        }
    }
}






int main()
{
    int b[N][N], n, row;

    zero_b(b);

    n = create_b(b);

    row = max_number(b, n);

    print_matrix(b, n, row);
}