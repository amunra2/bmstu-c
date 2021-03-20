#include"../inc/check_main.h"


//Positives

START_TEST(test_divisoin_normal)
{
    node_t *to_check = NULL;
    int rc = translate_num(&to_check, 2);
    assert(rc == NO_MISTAKES);

    node_t *res = NULL;
    rc = division(&res, 10, 5);
    assert(rc == NO_MISTAKES);

    rc = compare_lists(res, to_check);

    free_list(res);
    free_list(to_check);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_divisoin_by_one)
{
    node_t *to_check = NULL;
    int rc = translate_num(&to_check, 100);
    assert(rc == NO_MISTAKES);

    node_t *res = NULL;
    rc = division(&res, 100, 1);
    assert(rc == NO_MISTAKES);

    rc = compare_lists(res, to_check);

    free_list(res);
    free_list(to_check);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


//Negatives

START_TEST(test_divisoin_unright_nums)
{

    node_t *res = NULL;
    int rc = division(&res, 5, 7);

    free_list(res);

    ck_assert_int_eq(rc, ERR_DIVISION);
}
END_TEST


START_TEST(test_divisoin_by_zero)
{

    node_t *res = NULL;
    int rc = division(&res, 5, 0);

    free_list(res);

    ck_assert_int_eq(rc, ERR_ZERO_DIVISION);
}
END_TEST


START_TEST(test_divisoin_num_less_than_two)
{

    node_t *res = NULL;
    int rc = division(&res, 0, 1);

    free_list(res);

    ck_assert_int_eq(rc, ERR_TRANSLATE_NUM);
}
END_TEST



Suite *div_suite(Suite *s)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_divisoin_normal);
    tcase_add_test(tc_pos, test_divisoin_by_one);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_divisoin_unright_nums);
    tcase_add_test(tc_neg, test_divisoin_by_zero);
    tcase_add_test(tc_neg, test_divisoin_num_less_than_two);

    suite_add_tcase(s, tc_neg);

    return s;
}