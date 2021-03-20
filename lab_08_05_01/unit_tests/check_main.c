#include"../inc/check_main.h"


int compare_matrix(matrix_t mat1, matrix_t mat2)
{
    if (mat1.row != mat2.row)
    {
        return ERR_NOT_EQUAL_ROWS;
    }

    if (mat1.col != mat2.col)
    {
        return ERR_NOT_EQUAL_COLS;
    }
    

    for (int i = 0; i < mat1.row; i++)
    {
        for (int j = 0; j < mat2.col; j++)
        {
            if (mat1.matrix[i][j] != mat2.matrix[i][j])
            {
                return ERR_UNRIGHT_ELEMS;
            }
        }   
    }

    return OK_COMPARE;
}


void fill_matrix(matrix_t mat)
{
    int num = 1;

    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.matrix[i][j] = num++;
        }   
    }
}


Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    //funcs
    s = add_suite(s);
    s = delete_suite(s);
    s = power_suite(s);

    return s;
}


int main(void)
{
    Suite *s = tests_suite();

    SRunner *runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    int mistakes = srunner_ntests_failed(runner);

    srunner_free(runner);

    return mistakes;
}