#include"../inc/check_main.h"
#include"../inc/array_work.h"


START_TEST(test_sort_normal)
{
    int arr1[] = {89, 1, 5, 78, 150, 56, 5, 23, 99, 34};
    int len1 = 10;

    int arr2[] = {1, 5, 5, 23, 34, 56, 78, 89, 99, 150};
    int len2 = 10;

    mysort(arr1, len1, sizeof(int), compare);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_sort_reverse)
{
    int arr1[] = {150, 99, 89, 78, 56, 34, 23, 5, 5, 1};
    int len1 = 10;

    int arr2[] = {1, 5, 5, 23, 34, 56, 78, 89, 99, 150};
    int len2 = 10;

    mysort(arr1, len1, sizeof(int), compare);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_sort_sorted)
{
    int arr1[] = {1, 5, 5, 23, 34, 56, 78, 89, 99, 150};
    int len1 = 10;

    int arr2[] = {1, 5, 5, 23, 34, 56, 78, 89, 99, 150};
    int len2 = 10;

    mysort(arr1, len1, sizeof(int), compare);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_sort_one_elem)
{
    int arr1[] = {150};
    int len1 = 1;

    int arr2[] = {150};
    int len2 = 1;

    mysort(arr1, len1, sizeof(int), compare);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_sort_two_elems)
{
    int arr1[] = {150, 5};
    int len1 = 2;

    int arr2[] = {5, 150};
    int len2 = 2;

    mysort(arr1, len1, sizeof(int), compare);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_sort_neg_elems)
{
    int arr1[] = {-33, -77, -9, 0, -1};
    int len1 = 5;

    int arr2[] = {-77, -33, -9, -1, 0};
    int len2 = 5;

    mysort(arr1, len1, sizeof(int), compare);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


START_TEST(test_sort_equal_elems)
{
    int arr1[] = {7, 7, 7, 7, 7};
    int len1 = 5;

    int arr2[] = {7, 7, 7, 7, 7};
    int len2 = 5;

    mysort(arr1, len1, sizeof(int), compare);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, NO_MISTAKES);
}
END_TEST


Suite *sort_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_sort_normal);
    tcase_add_test(tc_pos, test_sort_reverse);
    tcase_add_test(tc_pos, test_sort_sorted);
    tcase_add_test(tc_pos, test_sort_one_elem);
    tcase_add_test(tc_pos, test_sort_two_elems);
    tcase_add_test(tc_pos, test_sort_equal_elems);
    tcase_add_test(tc_pos, test_sort_neg_elems);

    suite_add_tcase(s, tc_pos);

    return s;
}