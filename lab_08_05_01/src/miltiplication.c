#include"../inc/miltiplication.h"


void copy_matrix(matrix_t *mat1, matrix_t *mat2)
{
    for (int i = 0; i < mat1->row; i++)
    {
        for (int j = 0; j < mat1->col; j++)
        {
            mat2->matrix[i][j] = mat1->matrix[i][j];
        }
    }
}


void ones_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            if (i == j)
            {
                matrix->matrix[i][j] = 1;
            }
            else
            {
                matrix->matrix[i][j] = 0;
            }   
        }   
    }   
}

int check_int_overflow(int a, int b)
{
    signed long long c = (signed long long)a * (signed long long)b;
    
    if ((c < INT_MAX) && (c > INT_MIN))
    {
        return OK;
    }
    else
    {
        return OWERFLOW;
    }
}


int multi(matrix_t a_mat, matrix_t b_mat, matrix_t *result)
{
    int num = 0;


    for (int i = 0; i < a_mat.row; i++)
    {
        for (int j = 0; j < a_mat.col; j++)
        {
            num = 0;

            for (int k = 0; k < b_mat.col; k++)
            {
                if (check_int_overflow(a_mat.matrix[i][k], b_mat.matrix[k][j]))
                {
                    return ERR_INT_OVERFLOW;
                }

                num += a_mat.matrix[i][k] * b_mat.matrix[k][j];
            }

            result->matrix[i][j] = num;
        }
    }

    return OK_MULTI;
}


int power_matrix(matrix_t matrix, matrix_t *result, int power)
{
    int rc = allocate_matrix(result);

    if (rc != NO_MISTAKES)
    {
        return ERR_ALLOCATE_MATRIX;
    }

    if (power == 0)
    {
        ones_matrix(result);

        return OK_MULTI;
    }
    else if (power == 1)
    {
        copy_matrix(&matrix, result);

        return OK_MULTI;
    }

    matrix_t tmp;

    tmp.matrix = NULL;
    tmp.col = matrix.col;
    tmp.row = matrix.row;

    rc = allocate_matrix(&tmp);

    if (rc != 0)
    {
        return rc;
    }

    copy_matrix(&matrix, &tmp);

    int flag = 0;

    while (power > 1)
    {
        if (flag == 0)
        {
            multi(matrix, tmp, result);
            flag = 1;
        }
        else if (flag == 1)
        {
            multi(matrix, *result, &tmp);
            flag = 0;
        }

        power--;
    }

    if (flag == 0)
    {
        copy_matrix(&tmp, result);
    }

    free_matrix(tmp);

    return OK_MULTI; 
}