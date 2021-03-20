#include"../inc/parse_matrix.h"


int find_min(matrix_t *matrix, int type)
{
    int min_elem = matrix->matrix[0][0];

    int min_row = 0;
    int min_col = 0;

    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            if (matrix->matrix[i][j] < min_elem)
            {
                min_elem = matrix->matrix[i][j];
                min_row = i;
                min_col = j;
            }
        }
    }

    LOG_DEBUG("min row = %d, min col = %d", min_row, min_col);

    return (type == ROW_INDEX) ? min_row : min_col;
}


void swap_rows(matrix_t *matrix, int from, int to)
{
    int *tmp = matrix->matrix[from];
    matrix->matrix[from] = matrix->matrix[to];
    matrix->matrix[to] = tmp;
}


int delete_row(matrix_t *matrix)
{
    int min_row = find_min(matrix, ROW_INDEX);

    for (int i = min_row; i < matrix->row - 1; i++)
    {
        swap_rows(matrix, i, i + 1);
    }

    int rc = reallocate_matrix(matrix, matrix->row - 1, matrix->col);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    return OK_DELETE_ROW;
}


int delete_col(matrix_t *matrix)
{
    int min_col = find_min(matrix, COL_INDEX);

    for (int i = min_col; i < matrix->col - 1; i++)
    {
        for (int j = 0; j < matrix->row; j++)
        {
            int tmp = matrix->matrix[j][i];
            matrix->matrix[j][i] = matrix->matrix[j][i + 1];
            matrix->matrix[j][i + 1] = tmp;
        }
    }

    int rc = reallocate_matrix(matrix, matrix->row, matrix->col - 1);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    return OK_DELETE_COL;
}


int square_matrix(matrix_t *matrix)
{
    int rows = matrix->row, cols = matrix->col;

    matrix_t tmp = *matrix;

    int rc;

    if (rows > cols)
    {
        while (rows-- > cols)
        {
            rc = delete_row(&tmp);

            if (rc != NO_MISTAKES)
            {
                return rc;
            }
        }
    }
    else if (cols > rows)
    {
        while (cols-- > rows)
        {
            rc = delete_col(&tmp);

            if (rc != NO_MISTAKES)
            {
                return rc;
            }
        }
    }

    LOG_DEBUG("row = %d, col = %d", rows, cols);

    *matrix = tmp;

    return OK_PARSE_MATRIX;
}



int average_geometric(int **matrix, int place, int len)
{
    int avg_geo = 1;

    for (int i = 0; i < len; i++)
    {
        LOG_DEBUG("matrix[%d][%d] = %d", i, place, matrix[i][place]);
        avg_geo *= matrix[i][place];
    } 

    if (avg_geo < 0)
    {
        avg_geo *= -1;
    }

    LOG_DEBUG("avg = %d", avg_geo);

    double answer = pow(avg_geo, (double)1/len);

    LOG_DEBUG("after pow = %lf", answer);

    avg_geo = (int)floor(answer);

    LOG_DEBUG("after floor = %d", avg_geo);

    return avg_geo;
}



int add_row(matrix_t *matrix)
{
    int num;
    int new_row = matrix->row;

    for (int j = 0; j < matrix->col; j++)
    {
        num = average_geometric(matrix->matrix, j, matrix->row);

        matrix->matrix[new_row][j] = num;
        LOG_DEBUG("num after func = %d", num);
    }

    matrix->row++;

    return OK_ADD_ROW;
}


int find_max_in_row(int *row, int len)
{
    int max_elem = row[0];

    for (int i = 0; i < len; i++)
    {
        if (row[i] > max_elem)
        {
            max_elem = row[i];
        }
    }

    return max_elem;
}


int add_col(matrix_t *matrix)
{
    int new_col = matrix->col;
    int num;

    for (int i = 0; i < matrix->row; i++)
    {
        num = find_max_in_row(matrix->matrix[i], matrix->col);
        matrix->matrix[i][new_col] = num;
    }

    matrix->col++;

    return OK_ADD_COL;
}


int change_matrix_square(matrix_t *matrix, int size)
{
    int row = matrix->row, col = matrix->col;

    int rc = NO_MISTAKES;

    LOG_DEBUG("size = %d", size);

    rc = reallocate_matrix(matrix, size, size);
    matrix->row = row;
    matrix->col = col;
    
    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    while (row++ < size)
    {
        rc = add_row(matrix);

        if (rc != NO_MISTAKES)
        {
            return rc;
        }
    }

    while (col++ < size)
    {
        rc = add_col(matrix);

        if (rc != NO_MISTAKES)
        {
            return rc;
        }
    }

    LOG_DEBUG("col = %d, row = %d", col, row);

    matrix->col = size;
    matrix->row = size;

    return OK_CHANGE_MATRIX;
}