#include"../inc/check_main.h"
#include"../inc/array_work.h"


//Positives

START_TEST(test_filter_normal)
{
    int arr1_b[] = {89, 1, 5, 78, 150, 56, 5, 23, 99, 34};
    int *arr1_e = arr1_b + 10;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr2[] = {5, 78};
    int len2 = 2;

    key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    int len1 = pe_dst - pb_dst;

    int rc = compare_arrs(pb_dst, len1, arr2, len2);

    ck_assert_int_eq(rc, NO_MISTAKES);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_first_max)
{
    int arr1_b[] = {89, 1, 5, 78, 150, 1, 5, 23, 150, 34};
    int *arr1_e = arr1_b + 10;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr2[] = {5, 78};
    int len2 = 2;

    key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    int len1 = pe_dst - pb_dst;

    int rc = compare_arrs(pb_dst, len1, arr2, len2);

    ck_assert_int_eq(rc, NO_MISTAKES);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_min_after_max)
{
    int arr1_b[] = {89, 23, 150, 78, 23, 7, 5, 1, 23, 100};
    int *arr1_e = arr1_b + 10;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr2[] = {78, 23, 7, 5};
    int len2 = 4;

    key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    int len1 = pe_dst - pb_dst;

    int rc = compare_arrs(pb_dst, len1, arr2, len2);

    ck_assert_int_eq(rc, NO_MISTAKES);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_without_begin_and_end)
{
    int arr1_b[] = {1, 1, 5, 78, 150, 1, 5, 23, 150, 175};
    int *arr1_e = arr1_b + 10;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr2[] = {1, 5, 78, 150, 1, 5, 23, 150};
    int len2 = 8;

    key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    int len1 = pe_dst - pb_dst;

    int rc = compare_arrs(pb_dst, len1, arr2, len2);

    ck_assert_int_eq(rc, NO_MISTAKES);

    free(pb_dst);
}
END_TEST


//Negatives

START_TEST(test_filter_equal_elems)
{
    int arr1_b[] = {7, 7, 7, 7, 7};
    int *arr1_e = arr1_b + 5;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERR_THE_SAME_ELEMENTS);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_no_elems_between_min_max)
{
    int arr1_b[] = {7, 1, 15, 7, 7};
    int *arr1_e = arr1_b + 5;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERR_UNRIGHT_SIZE);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_only_one_elem_in_array)
{
    int arr1_b[] = {7};
    int *arr1_e = arr1_b + 1;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERR_UNRIGHT_SIZE);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_unright_pointers)
{
    int arr1_b[] = {7, 3, 10, 15, 25};
    int *arr1_e = arr1_b - 1;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERR_UNRIGHNT_INPUT);

    free(pb_dst);
}
END_TEST



Suite *key_suite(Suite *s)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_filter_normal);
    tcase_add_test(tc_pos, test_filter_first_max);
    tcase_add_test(tc_pos, test_filter_min_after_max);
    tcase_add_test(tc_pos, test_filter_without_begin_and_end);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_filter_equal_elems);
    tcase_add_test(tc_neg, test_filter_no_elems_between_min_max);
    tcase_add_test(tc_neg, test_filter_only_one_elem_in_array);
    tcase_add_test(tc_neg, test_filter_unright_pointers);

    suite_add_tcase(s, tc_neg);

    return s;
}