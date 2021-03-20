#include"../inc/matrix_work.h"


void free_all_matrixes(matrix_t a, matrix_t b, matrix_t c)
{
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);    
}


int read_matrix(matrix_t *matrix)
{
    int rows, columns;

    if ((scanf("%d", &rows) != OK_READ_ELEM) || (rows < 1))
    {
        return ERR_UNRIGHT_ROW_INPUT;
    }

    LOG_DEBUG("rows = %d", rows);

    if ((scanf("%d", &columns) != OK_READ_ELEM) || (columns < 1))
    {
        return ERR_UNRIGHT_COLUMN_INPUT;
    }

    LOG_DEBUG("columns = %d", columns);

    matrix_t tmp = {.matrix = NULL, .col = columns, .row = rows};

    LOG_DEBUG("tmp.columns = %d", tmp.col);

    int rc = allocate_matrix(&tmp);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Memory error, code = %d", rc);
        return ERR_ALLOCATE_MATRIX;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (scanf("%d", &tmp.matrix[i][j]) != OK_READ_ELEM)
            {
                free_matrix(tmp);
                return ERR_UNRIGHT_MATRIX_ELEM;
            }

            LOG_DEBUG("elem[%d][%d] = %d", i, j, tmp.matrix[i][j]);
        }
    }

    *matrix = tmp;

    return OK_READ_MATRIX;
}


void print_matrix(matrix_t matrix)
{
    LOG_INFO("%s", "In print func\n");
    LOG_DEBUG("ROWS = %d", matrix.row);

    for (int i = 0; i < matrix.row; i++)
    {
        for (int j = 0; j < matrix.col; j++)
        {
            printf("%3d ", matrix.matrix[i][j]);
        }

        puts("");
    }
}


int make_square_all(matrix_t *a_mat, matrix_t *b_mat)
{
    int rc = square_matrix(a_mat);
    
    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Parse matrix error, code = %d", rc);
        free_matrix(*a_mat);
        free_matrix(*b_mat);
        return rc;
    }

    rc = square_matrix(b_mat);
    
    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Parse matrix error, code = %d", rc);
        free_matrix(*a_mat);
        free_matrix(*b_mat);
        return rc;
    }

    return OK_SQUARE_MATRIX;
}


int read_all(matrix_t *a_mat, matrix_t *b_mat)
{
    int rc = read_matrix(a_mat);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Read matrix A error, code = %d", rc);
        return rc;
    }

    rc = read_matrix(b_mat);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Read matrix error, code = %d", rc);
        free_matrix(*a_mat);
        return rc;
    }

    rc = make_square_all(a_mat, b_mat);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    return OK_READ;    
}


int make_matrix_equal_size(matrix_t *a_mat, matrix_t *b_mat)
{
    int rc = NO_MISTAKES;

    if (a_mat->row > b_mat->row)
    {
        rc = change_matrix_square(b_mat, a_mat->row);

        if (rc != NO_MISTAKES)
        {
            LOG_ERROR("Change matrix A error, code = %d", rc);
            free_matrix(*a_mat);
            free_matrix(*b_mat);
            return rc;
        }
    }
    else if (b_mat->row > a_mat->row)
    {
        rc = change_matrix_square(a_mat, b_mat->row);
        
        if (rc != NO_MISTAKES)
        {
            LOG_ERROR("Change matrix B error, code = %d", rc);
            free_matrix(*a_mat);
            free_matrix(*b_mat);
            return rc;
        }
    }

    return OK_EQUAL_SIZES;
}


int power_matrix_all(matrix_t a_mat, matrix_t *result_a, matrix_t b_mat, matrix_t *result_b)
{
    int power_a, power_b;

    if ((scanf("%d %d", &power_a, &power_b) != OK_READ_GRADES) || (power_a < 0) || (power_b < 0))
    {
        LOG_ERROR("Uright grade error, code = %d", ERR_UNRIGHT_POWER);
        free_matrix(a_mat);
        free_matrix(b_mat);
        return ERR_UNRIGHT_POWER;
    }

    int rc = power_matrix(a_mat, result_a, power_a);

    free_matrix(a_mat);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Grade matrix A error, code = %d", rc);
        free_matrix(b_mat);
        free_matrix(*result_a);
        return rc;
    }

    rc = power_matrix(b_mat, result_b, power_b);

    free_matrix(b_mat);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Grade matrix B error, code = %d", rc);
        free_matrix(*result_a);
        free_matrix(*result_b);
        return rc;
    }

    return OK_POWER_ALL;
}


int power_and_multiply(matrix_t a_mat, matrix_t b_mat)
{
    matrix_t result_a = {.matrix = NULL, .col = a_mat.col, .row = a_mat.row};
    matrix_t result_b = {.matrix = NULL, .col = b_mat.col, .row = b_mat.row};

    int rc = power_matrix_all(a_mat, &result_a, b_mat, &result_b);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }     

    matrix_t result = {.matrix = NULL, .col = b_mat.col, .row = b_mat.row};
    
    rc = allocate_matrix(&result);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Allocate matrix error, code = %d", rc);
        free_matrix(result_a);
        free_matrix(result_b);
        return rc;
    }

    rc = multi(result_a, result_b, &result);

    if (rc != NO_MISTAKES)
    {
        free_all_matrixes(result_a, result_b, result);
        return rc;        
    }

    print_matrix(result);
    free_all_matrixes(result_a, result_b, result);

    return OK_MULTI;
}


int matrix_work(void)
{
    matrix_t a_mat, b_mat;
    int rc = read_all(&a_mat, &b_mat);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    rc = make_square_all(&a_mat, &b_mat);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    rc = make_matrix_equal_size(&a_mat, &b_mat);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    rc = power_and_multiply(a_mat, b_mat);
    
    if (rc != NO_MISTAKES)
    {
        return rc;
    }
    
    return OK_MULTIPLICATE;
}