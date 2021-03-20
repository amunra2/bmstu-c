#include"../inc/check_main.h"


//Positives

START_TEST(test_pop_front_normal)
{
    int num = 5;

    node_t *list = NULL;

    int rc = push_node_front(&list, &num);
    assert(rc == NO_MISTAKES);

    void *num_res = pop_front(&list);

    ck_assert_int_eq(*(int*)num_res, 5);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST


START_TEST(test_pop_back_normal)
{
    int num = 5;

    node_t *list = NULL;

    int rc = push_node_front(&list, &num);
    assert(rc == NO_MISTAKES);

    void *num_res = pop_back(&list);

    ck_assert_int_eq(*(int*)num_res, 5);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST


//Negatives

START_TEST(test_pop_front_empty_list)
{
    node_t *list = NULL;

    void *num = pop_front(&list);

    ck_assert_ptr_eq(num, NULL);
}
END_TEST


START_TEST(test_pop_back_empty_list)
{
    node_t *list = NULL;

    void *num = pop_back(&list);

    ck_assert_ptr_eq(num, NULL);
}
END_TEST



Suite *pop_suite(Suite *s)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_pop_front_normal);
    tcase_add_test(tc_pos, test_pop_back_normal);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_pop_front_empty_list);
    tcase_add_test(tc_neg, test_pop_back_empty_list);

    suite_add_tcase(s, tc_neg);

    return s;
}