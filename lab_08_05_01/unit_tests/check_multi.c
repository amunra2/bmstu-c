#include"../inc/check_main.h"
#include"../inc/miltiplication.h"


//Positives

START_TEST(test_grade_2)
{
    matrix_t start = {.col = 3, .row = 3, .matrix = NULL};

    allocate_matrix(&start);

    fill_matrix(start);

    matrix_t end = {.col = 3, .row = 3, .matrix = NULL};

    allocate_matrix(&end);

    end.matrix[0][0] = 30;
    end.matrix[0][1] = 36;
    end.matrix[0][2] = 42;
    end.matrix[1][0] = 66;
    end.matrix[1][1] = 81;
    end.matrix[1][2] = 96;
    end.matrix[2][0] = 102;
    end.matrix[2][1] = 126;
    end.matrix[2][2] = 150;

    matrix_t result = {.col = 3, .row = 3, .matrix = NULL};

    //allocate_matrix(&result);

    power_matrix(start, &result, 2);
    
    int rc = compare_matrix(result, end);

    free_matrix(start);
    free_matrix(result);
    free_matrix(end);

    ck_assert_int_eq(rc, NO_MISTAKES);  
}
END_TEST


START_TEST(test_grade_1)
{
    matrix_t start = {.col = 3, .row = 3, .matrix = NULL};

    allocate_matrix(&start);

    fill_matrix(start);

    matrix_t end = {.col = 3, .row = 3, .matrix = NULL};

    allocate_matrix(&end);

    end.matrix[0][0] = 1;
    end.matrix[0][1] = 2;
    end.matrix[0][2] = 3;
    end.matrix[1][0] = 4;
    end.matrix[1][1] = 5;
    end.matrix[1][2] = 6;
    end.matrix[2][0] = 7;
    end.matrix[2][1] = 8;
    end.matrix[2][2] = 9;

    matrix_t result = {.col = 3, .row = 3, .matrix = NULL};

    //allocate_matrix(&result);

    power_matrix(start, &result, 1);
    
    int rc = compare_matrix(result, end);

    free_matrix(start);
    free_matrix(result);
    free_matrix(end);

    ck_assert_int_eq(rc, NO_MISTAKES);  
}
END_TEST


START_TEST(test_grade_0)
{
    matrix_t start = {.col = 3, .row = 3, .matrix = NULL};

    allocate_matrix(&start);

    fill_matrix(start);

    matrix_t end = {.col = 3, .row = 3, .matrix = NULL};

    allocate_matrix(&end);

    end.matrix[0][0] = 1;
    end.matrix[0][1] = 0;
    end.matrix[0][2] = 0;
    end.matrix[1][0] = 0;
    end.matrix[1][1] = 1;
    end.matrix[1][2] = 0;
    end.matrix[2][0] = 0;
    end.matrix[2][1] = 0;
    end.matrix[2][2] = 1;

    matrix_t result = {.col = 3, .row = 3, .matrix = NULL};

    //allocate_matrix(&result);

    power_matrix(start, &result, 0);
    
    int rc = compare_matrix(result, end);

    free_matrix(start);
    free_matrix(result);
    free_matrix(end);

    ck_assert_int_eq(rc, NO_MISTAKES);  
}
END_TEST


Suite *power_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_grade_2);
    tcase_add_test(tc_pos, test_grade_1);
    tcase_add_test(tc_pos, test_grade_0);

    suite_add_tcase(s, tc_pos);

    return s;
}