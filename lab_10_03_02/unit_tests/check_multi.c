#include"../inc/check_main.h"


//Positives

START_TEST(test_multi_normal)
{
    node_t *a = NULL;
    int rc = translate_num(&a, 4);
    assert(rc == NO_MISTAKES);

    node_t *b = NULL;
    rc = translate_num(&b, 3);
    assert(rc == NO_MISTAKES);

    rc = multiply(a, b);
    assert(rc == NO_MISTAKES);

    node_t *res = NULL;
    rc = translate_num(&res, 12);
    assert(rc == NO_MISTAKES);

    rc = compare_lists(a, res);

    free_list(a);
    free_list(b);
    free_list(res);

    ck_assert_int_eq(rc, 0);
}
END_TEST


START_TEST(test_multi_equal_nums)
{
    node_t *a = NULL;
    int rc = translate_num(&a, 5);
    assert(rc == NO_MISTAKES);

    node_t *b = NULL;
    rc = translate_num(&b, 5);
    assert(rc == NO_MISTAKES);

    rc = multiply(a, b);
    assert(rc == NO_MISTAKES);

    node_t *res = NULL;
    rc = translate_num(&res, 25);
    assert(rc == NO_MISTAKES);

    rc = compare_lists(a, res);

    free_list(a);
    free_list(b);
    free_list(res);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_multi_big_nums)
{
    node_t *a = NULL;
    int rc = translate_num(&a, 1000);
    assert(rc == NO_MISTAKES);

    node_t *b = NULL;
    rc = translate_num(&b, 30);
    assert(rc == NO_MISTAKES);

    rc = multiply(a, b);
    assert(rc == NO_MISTAKES);

    node_t *res = NULL;
    rc = translate_num(&res, 30000);
    assert(rc == NO_MISTAKES);

    rc = compare_lists(a, res);

    free_list(a);
    free_list(b);
    free_list(res);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


//Negatives

START_TEST(test_multi_first_num_none)
{
    node_t *a = NULL;

    node_t *b = NULL;
    int rc = translate_num(&b, 30);
    assert(rc == NO_MISTAKES);

    rc = multiply(a, b);

    free_list(b);

    ck_assert_int_eq(rc, ERR_LIST_EMPTY);
}
END_TEST


START_TEST(test_multi_second_num_none)
{
    node_t *a = NULL;
    int rc = translate_num(&a, 30);
    assert(rc == NO_MISTAKES);

    node_t *b = NULL;

    free_list(a);

    rc = multiply(a, b);

    ck_assert_int_eq(rc, ERR_LIST_EMPTY);
}
END_TEST



Suite *multi_suite(Suite *s)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_multi_normal);
    tcase_add_test(tc_pos, test_multi_equal_nums);
    tcase_add_test(tc_pos, test_multi_big_nums);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_multi_first_num_none);
    tcase_add_test(tc_neg, test_multi_second_num_none);

    suite_add_tcase(s, tc_neg);

    return s;
}