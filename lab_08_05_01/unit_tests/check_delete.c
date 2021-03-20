#include"../inc/check_main.h"
#include"../inc/parse_matrix.h"


//Positives

START_TEST(test_parse_delete_columns)
{
    matrix_t start = {.col = 5, .row = 2, .matrix = NULL};

    allocate_matrix(&start);

    fill_matrix(start);

    matrix_t end = {.col = 2, .row = 2, .matrix = NULL};

    allocate_matrix(&end);

    end.matrix[0][0] = 4;
    end.matrix[0][1] = 5;
    end.matrix[1][0] = 9;
    end.matrix[1][1] = 10;

    square_matrix(&start);
    

    int rc = compare_matrix(start, end);

    free_matrix(start);
    free_matrix(end);

    ck_assert_int_eq(rc, NO_MISTAKES);  
}
END_TEST



START_TEST(test_parse_delete_rows)
{
    matrix_t start = {.col = 2, .row = 3, .matrix = NULL};

    allocate_matrix(&start);

    fill_matrix(start);

    matrix_t end = {.col = 2, .row = 2, .matrix = NULL};

    allocate_matrix(&end);

    end.matrix[0][0] = 3;
    end.matrix[0][1] = 4;
    end.matrix[1][0] = 5;
    end.matrix[1][1] = 6;

    square_matrix(&start);
    
    int rc = compare_matrix(start, end);

    free_matrix(start);
    free_matrix(end);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST



START_TEST(test_parse_nothinng_to_delete)
{
    matrix_t start = {.col = 2, .row = 2, .matrix = NULL};

    allocate_matrix(&start);

    fill_matrix(start);

    matrix_t end = {.col = 2, .row = 2, .matrix = NULL};

    allocate_matrix(&end);

    end.matrix[0][0] = 1;
    end.matrix[0][1] = 2;
    end.matrix[1][0] = 3;
    end.matrix[1][1] = 4;

    square_matrix(&start);
    
    int rc = compare_matrix(start, end);

    free_matrix(start);
    free_matrix(end);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_parse_equal_elems)
{
    matrix_t start = {.col = 3, .row = 2, .matrix = NULL};

    allocate_matrix(&start);

    start.matrix[0][0] = 1;
    start.matrix[0][1] = 1;
    start.matrix[0][2] = 1;
    start.matrix[1][0] = 1;
    start.matrix[1][1] = 1;
    start.matrix[1][2] = 1;

    matrix_t end = {.col = 2, .row = 2, .matrix = NULL};

    allocate_matrix(&end);

    end.matrix[0][0] = 1;
    end.matrix[0][1] = 1;
    end.matrix[1][0] = 1;
    end.matrix[1][1] = 1;

    square_matrix(&start);
    
    int rc = compare_matrix(start, end);

    free_matrix(start);
    free_matrix(end);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST



Suite *delete_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_parse_delete_columns);
    tcase_add_test(tc_pos, test_parse_delete_rows);
    tcase_add_test(tc_pos, test_parse_nothinng_to_delete);
    tcase_add_test(tc_pos, test_parse_equal_elems);

    suite_add_tcase(s, tc_pos);

    return s;
}