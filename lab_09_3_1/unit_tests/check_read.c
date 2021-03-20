#include"../inc/check_main.h"


//Positives

START_TEST(test_read_normal)
{
    FILE *f = fopen("./func_tests/pos_04_in.txt", "r");

    product_t *prod_arr = NULL;
    int count = 0;
    
    read_file(f, &prod_arr, &count);

    product_t prod_result[4];

    prod_result[0].name = "one";
    prod_result[1].name = "two";
    prod_result[2].name = "three";
    prod_result[3].name = "four";

    prod_result[0].price = 1;
    prod_result[1].price = 2;
    prod_result[2].price = 3;
    prod_result[3].price = 4;

    int rc = compare_arrs(prod_arr, count, prod_result, 4);

    ck_assert_int_eq(rc, NO_MISTAKES);

    free_structs(prod_arr, count);
}
END_TEST


//Negatives

START_TEST(test_read_wrong_elems_in_the_first_row)
{
    FILE *f = fopen("./func_tests/neg_09_in.txt", "r");

    product_t *prod_arr = NULL;
    int count = 0;
    
    int rc = read_file(f, &prod_arr, &count);

    ck_assert_int_eq(rc, ERR_WRONG_NUM_PRODUCTS);

    free_structs(prod_arr, count);
}
END_TEST


START_TEST(test_read_wrong_first_field)
{
    FILE *f = fopen("./func_tests/neg_02_in.txt", "r");

    product_t *prod_arr = NULL;
    int count = 0;
    
    int rc = read_file(f, &prod_arr, &count);

    ck_assert_int_eq(rc, WRONG_NUM);
}
END_TEST


START_TEST(test_read_wrong_second_field)
{
    FILE *f = fopen("./func_tests/neg_03_in.txt", "r");

    product_t *prod_arr = NULL;
    int count = 0;
    
    int rc = read_file(f, &prod_arr, &count);

    ck_assert_int_eq(rc, WRONG_NUM);
}
END_TEST


START_TEST(test_read_clear_file)
{
    FILE *f = fopen("./func_tests/neg_01_in.txt", "r");

    product_t *prod_arr = NULL;
    int count = 0;
    
    int rc = read_file(f, &prod_arr, &count);

    ck_assert_int_eq(rc, ERR_FILE_CLEAR);
}
END_TEST


START_TEST(test_read_num_of_structs_are_different)
{
    FILE *f = fopen("./func_tests/neg_08_in.txt", "r");

    product_t *prod_arr = NULL;
    int count = 0;
    
    int rc = read_file(f, &prod_arr, &count);

    ck_assert_int_eq(rc, WRONG_NUM_STRUCTURES);
}
END_TEST


START_TEST(test_read_negative_second_field)
{
    FILE *f = fopen("./func_tests/neg_04_in.txt", "r");

    product_t *prod_arr = NULL;
    int count = 0;
    
    int rc = read_file(f, &prod_arr, &count);

    ck_assert_int_eq(rc, NEGATIVE_PRICE);
}
END_TEST


Suite *read_suite(Suite *s)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_read_normal);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_read_wrong_elems_in_the_first_row);
    tcase_add_test(tc_neg, test_read_wrong_first_field);
    tcase_add_test(tc_neg, test_read_wrong_second_field);
    tcase_add_test(tc_neg, test_read_clear_file);
    tcase_add_test(tc_neg, test_read_num_of_structs_are_different);
    tcase_add_test(tc_neg, test_read_negative_second_field);

    suite_add_tcase(s, tc_neg);

    return s;
}