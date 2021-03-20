#include"../inc/memory_work.h"


void free_matrix(matrix_t matrix)
{
    for (int ind = 0; ind < matrix.row; ind++)
    {
        free(matrix.matrix[ind]);
    }

    free(matrix.matrix);
}


int allocate_matrix(matrix_t *matrix)
{
    matrix_t tmp;

    tmp.matrix = NULL;
    tmp.col = matrix->col;
    tmp.row = matrix->row;

    tmp.matrix = malloc(matrix->row * sizeof(int*));

    if (!tmp.matrix)
    {
        return ERR_ALLOCATE_MATRIX;
    }

    for (int ind = 0; ind < matrix->row; ind++)
    {
        tmp.matrix[ind] = malloc(matrix->col * sizeof(int));

        if (!tmp.matrix[ind])
        {
            tmp.row = ind + 1;
            free_matrix(tmp);

            return ERR_ALLOCATE_MATRIX;
        }
    }

    *matrix = tmp;

    return OK_ALLOCATE;
}


int reallocate_matrix(matrix_t *mat, int new_row, int new_col)
{
    if (new_row < mat->row)
    {
        for (int i = new_row; i < mat->row; i++)
        {
            free(mat->matrix[i]);
        }

        mat->row = new_row;
    }

    int **tmp = realloc(mat->matrix, new_row * sizeof(int*));

    if (!tmp)
    {
        return ERR_ALLOCATE_MATRIX;
    }

    mat->matrix = tmp;

    int *cur_tmp = NULL;

    for (int i = 0; i < mat->row; i++)
    {
        cur_tmp = realloc(mat->matrix[i], new_col * sizeof(int));

        if (!cur_tmp)
        {
            free_matrix(*mat);
            return ERR_ALLOCATE_MATRIX;
        }

        mat->matrix[i] = cur_tmp;
    }


    for (int i = mat->row; i < new_row; i++)
    {
        mat->matrix[i] = malloc(new_col * sizeof(int));

        if (!mat->matrix[i])
        {
            mat->row = i + 1;
            free_matrix(*mat);
            return ERR_ALLOCATE_MATRIX;
        }
    }

    mat->row = new_row;
    mat->col = new_col;

    return OK_ALLOCATE;
}