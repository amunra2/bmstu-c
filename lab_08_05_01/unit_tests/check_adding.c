#include"../inc/check_main.h"
#include"../inc/parse_matrix.h"


//Positives

START_TEST(test_change_nothing_to_add)
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

    change_matrix_square(&start, 2);
    
    int rc = compare_matrix(start, end);

    free_matrix(start);
    free_matrix(end);

    ck_assert_int_eq(rc, NO_MISTAKES);  
}
END_TEST

START_TEST(test_change_elems_different)
{
    matrix_t start = {.col = 2, .row = 2, .matrix = NULL};

    allocate_matrix(&start);

    fill_matrix(start);

    matrix_t end = {.col = 3, .row = 3, .matrix = NULL};

    allocate_matrix(&end);

    end.matrix[0][0] = 1;
    end.matrix[0][1] = 2;
    end.matrix[0][2] = 2;
    end.matrix[1][0] = 3;
    end.matrix[1][1] = 4;
    end.matrix[1][2] = 4;
    end.matrix[2][0] = 1;
    end.matrix[2][1] = 2;
    end.matrix[2][2] = 2;

    change_matrix_square(&start, 3);
    
    int rc = compare_matrix(start, end);

    free_matrix(start);
    free_matrix(end);

    ck_assert_int_eq(rc, NO_MISTAKES);  
}
END_TEST


START_TEST(test_change_elems_equal)
{
    matrix_t start = {.col = 2, .row = 2, .matrix = NULL};

    allocate_matrix(&start);

    start.matrix[0][0] = 7;
    start.matrix[0][1] = 7;
    start.matrix[1][0] = 7;
    start.matrix[1][1] = 7;


    matrix_t end = {.col = 3, .row = 3, .matrix = NULL};

    allocate_matrix(&end);

    end.matrix[0][0] = 7;
    end.matrix[0][1] = 7;
    end.matrix[0][2] = 7;
    end.matrix[1][0] = 7;
    end.matrix[1][1] = 7;
    end.matrix[1][2] = 7;
    end.matrix[2][0] = 7;
    end.matrix[2][1] = 7;
    end.matrix[2][2] = 7;

    change_matrix_square(&start, 3);
    
    int rc = compare_matrix(start, end);

    free_matrix(start);
    free_matrix(end);

    ck_assert_int_eq(rc, NO_MISTAKES);  
}
END_TEST


Suite *add_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_change_elems_different);
    tcase_add_test(tc_pos, test_change_elems_equal);
    tcase_add_test(tc_pos, test_change_nothing_to_add);

    suite_add_tcase(s, tc_pos);

    return s;
}