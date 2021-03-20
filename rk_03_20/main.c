#include"func.h"


int main(void)
{
    int rows, cols;

    if (scanf("%d %d", &rows, &cols) != 2)
    {
        return ERR_READ_SIZE;
    }

    LOG_DEBUG("r = %d, c = %d", rows, cols);

    matrix_t mat = {.matrix = NULL, .n = rows, .m = cols};

    int rc = allocate_matrix(&mat);

    LOG_DEBUG("%s", "ok allocate");

    if (rc != NO_MISTAKES)
    {
        return ERR_ALLOCATE_MATRIX;
    }
    

    rc = read_matrix(&mat);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    //print_matrix(mat);

    change_elems(&mat);

    LOG_DEBUG("%s", "ok change");

    //print_matrix(mat);

    rc = check_delete(&mat);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    LOG_DEBUG("%s", "ok print");

    print_matrix(mat);    


    free_matrix(mat);

    return OK;
}