#include"func.h"


void free_matrix(matrix_t mat)
{
    for (int i = 0; i < mat.n; i++)
    {
        free(mat.matrix[i]);
    }

    free(mat.matrix);
}


int allocate_matrix(matrix_t *mat)
{
    int **data = NULL;

    data = calloc(mat->n, sizeof(int*));

    if (!data)
    {
        return ERR_ALLOCATE_MATRIX;
    }

    for (int i = 0; i < mat->n; i++)
    {
        data[i] = malloc(mat->m * sizeof(int));

        if (!data[i])
        {
            free_matrix(*mat);
            return ERR_ALLOCATE_MATRIX;
        }
    }

    mat->matrix = data;

    return OK_ALLOCATE;
}



int read_matrix(matrix_t *mat)
{
    //int **tmp_mat = mat->matrix;

    int num;

    for (int i = 0; i < mat->n; i++)
    {
        for (int j = 0; j < mat->m; j++)
        {
            if (scanf("%d", &num) != 1)
            {
                return ERR_READ_ELEM;
            }

            mat->matrix[i][j] = num;
        }
    }

    return OK_READ;
}


void print_matrix(matrix_t mat)
{
    for (int i = 0; i < mat.n; i++)
    {
        for (int j = 0; j < mat.m; j++)
        {
            printf("%3d", mat.matrix[i][j]);
        }

        puts("");
    }
}


int reallocate_matrix(matrix_t *mat)
{
    LOG_DEBUG("%s", "in realloc");

    int place = mat->n - 1;

    free(mat->matrix[place]);

    int **tmp = realloc(mat->matrix, place * sizeof(int*));

    if (!tmp)
    {
        return ERR_ALLOCATE_MATRIX;;
    }

    LOG_DEBUG("%s", "after realloc");

    mat->matrix = tmp;

    mat->n -= 1;

    return OK_ALLOCATE;
}


void swap_rows(matrix_t *mat, int i, int j)
{
    int *tmp = mat->matrix[i];
    mat->matrix[i] = mat->matrix[j];
    mat->matrix[j] = tmp;
}


int delete_row(matrix_t *mat, int row)
{
    int rc;

    for (int i = row; i < mat->n - 1; i++)
    {
        swap_rows(mat, i, i + 1);
    }

    //print_matrix(*mat);

    rc = reallocate_matrix(mat);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    return OK_DELETE_ROW;
}



int check_delete(matrix_t *mat)
{
    int zeroes = 0;

    for (int i = 0; i < mat->n; i++)
    {
        zeroes = 0;

        for (int j = 0; j < mat->m; j++)
        {
            if (mat->matrix[i][j] == 0)
            {
                zeroes++;
            }
        }

        if (zeroes == mat->m)
        {
            LOG_DEBUG("row zeroes = %d", i);

            int rc = delete_row(mat, i);

            if (rc != NO_MISTAKES)
            {
                return rc;
            }

            i--;
        }
    }

    return OK_DELETE_ROW;
}


int count_elems(matrix_t *mat, int i, int j)
{
    int count = 0;

    if (i - 1 >= 0)
    {
        if (mat->matrix[i - 1][j] == -1)
        {
            count++;
        }
    }

    if (i + 1 < mat->n)
    {
        if (mat->matrix[i + 1][j] == -1)
        {
            count++;
        }        
    }

    if (j - 1 >= 0)
    {
        if (mat->matrix[i][j - 1] == -1)
        {
            count++;
        }
    }

    if (j + 1 < mat->m)
    {
        if (mat->matrix[i][j + 1] == -1)
        {
            count++;
        }        
    }

    if ((j - 1 >= 0) && (i - 1 >= 0))
    {
        if (mat->matrix[i - 1][j - 1] == -1)
        {
            count++;
        }         
    }

    if ((j + 1 < mat->m) && (i + 1 < mat->n))
    {
        if (mat->matrix[i + 1][j + 1] == -1)
        {
            count++;
        }         
    }

    if ((j - 1 >= 0) && (i + 1 < mat->m))
    {
        if (mat->matrix[i + 1][j - 1] == -1)
        {
            count++;
        }         
    }

    if ((j + 1 < mat->n) && (i - 1 >= 0))
    {
        if (mat->matrix[i - 1][j + 1] == -1)
        {
            count++;
        }         
    }

    return count;
}



void change_elems(matrix_t *mat)
{
    int elems;

    for (int i = 0; i < mat->n; i++)
    {
        for (int j = 0; j < mat->m; j++)
        {
            if (mat->matrix[i][j] == 0)
            {
                elems = count_elems(mat, i, j);

                mat->matrix[i][j] = elems;
            }
        }
    }
}