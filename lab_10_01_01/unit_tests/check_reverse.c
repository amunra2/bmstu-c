#include"../inc/check_main.h"


//Positives

START_TEST(test_reverse_normal)
{
    node_t *list1 = NULL;
    int arr1[5] = {1, 2, 3, 4, 5};

    int rc = make_list(&list1, arr1, 5);
    assert(rc == NO_MISTAKES);

    node_t *list2 = NULL;
    int arr2[5] = {5, 4, 3, 2, 1};

    rc = make_list(&list2, arr2, 5);
    assert(rc == NO_MISTAKES);

    node_t *new_list = reverse(list1);
    assert(new_list != NULL);

    rc = compare_lists(new_list, list2);

    free_list(new_list);
    free_list(list2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_reverse_equal)
{
    node_t *list1 = NULL;
    int arr1[5] = {5, 5, 5, 5, 5};

    int rc = make_list(&list1, arr1, 5);
    assert(rc == NO_MISTAKES);

    node_t *list2 = NULL;
    int arr2[5] = {5, 5, 5, 5, 5};

    rc = make_list(&list2, arr2, 5);
    assert(rc == NO_MISTAKES);

    node_t *new_list = reverse(list1);
    assert(new_list != NULL);

    rc = compare_lists(new_list, list2);

    free_list(new_list);
    free_list(list2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_reverse_random)
{
    node_t *list1 = NULL;
    int arr1[5] = {4, 1, 3, 2, 5};

    int rc = make_list(&list1, arr1, 5);
    assert(rc == NO_MISTAKES);

    node_t *list2 = NULL;
    int arr2[5] = {5, 2, 3, 1, 4};

    rc = make_list(&list2, arr2, 5);
    assert(rc == NO_MISTAKES);

    node_t *new_list = reverse(list1);
    assert(new_list != NULL);

    rc = compare_lists(new_list, list2);

    free_list(new_list);
    free_list(list2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_reverse_one_el)
{
    node_t *list1 = NULL;
    int arr1[1] = {5};

    int rc = make_list(&list1, arr1, 1);
    assert(rc == NO_MISTAKES);

    node_t *list2 = NULL;
    int arr2[1] = {5};

    rc = make_list(&list2, arr2, 1);
    assert(rc == NO_MISTAKES);

    node_t *new_list = reverse(list1);
    assert(new_list != NULL);

    rc = compare_lists(new_list, list2);

    free_list(new_list);
    free_list(list2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_reverse_two_els)
{
    node_t *list1 = NULL;
    int arr1[2] = {1, 2};

    int rc = make_list(&list1, arr1, 2);
    assert(rc == NO_MISTAKES);

    node_t *list2 = NULL;
    int arr2[2] = {2, 1};

    rc = make_list(&list2, arr2, 2);
    assert(rc == NO_MISTAKES);

    node_t *new_list = reverse(list1);
    assert(new_list != NULL);

    rc = compare_lists(new_list, list2);

    free_list(new_list);
    free_list(list2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


//Negatives

START_TEST(test_reverse_no_els)
{
    node_t *list1 = NULL;

    node_t *list2 = NULL;

    node_t *new_list = reverse(list1);

    ck_assert_ptr_eq(new_list, list2);
}
END_TEST



Suite *sort_suite(Suite *s)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_reverse_normal);
    tcase_add_test(tc_pos, test_reverse_equal);
    tcase_add_test(tc_pos, test_reverse_random);
    tcase_add_test(tc_pos, test_reverse_one_el);
    tcase_add_test(tc_pos, test_reverse_two_els);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_reverse_no_els);

    suite_add_tcase(s, tc_neg);

    return s;
}