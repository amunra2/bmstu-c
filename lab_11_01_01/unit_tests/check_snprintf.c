#include"../inc/check_main.h"


//Positives

START_TEST(test_snprintf_hd_normal)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    short int data = SHRT_MAX;

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "%hd", data);
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "%hd", data);

    ck_assert_int_eq(len_my_snprintf, len_snprintf);
    ck_assert_str_eq(test_my_snprintf, test_snprintf);
}
END_TEST


START_TEST(test_snprintf_hd_zero)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    short int data = 0;

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "%hd", data);
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "%hd", data);

    ck_assert_int_eq(len_my_snprintf, len_snprintf);
    ck_assert_str_eq(test_my_snprintf, test_snprintf);
}
END_TEST


START_TEST(test_snprintf_hd_negative_num)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    short int data = SHRT_MIN;

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "%hd", data);
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "%hd", data);

    ck_assert_int_eq(len_my_snprintf, len_snprintf);
    ck_assert_str_eq(test_my_snprintf, test_snprintf);
}
END_TEST


START_TEST(test_snprintf_c_normal)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    char data = 'u';

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "%c", data);
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "%c", data);

    ck_assert_int_eq(len_my_snprintf, len_snprintf);
    ck_assert_str_eq(test_my_snprintf, test_snprintf);
}
END_TEST


START_TEST(test_snprintf_s_normal)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    char *data = "string test";

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "%s", data);
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "%s", data);

    ck_assert_int_eq(len_my_snprintf, len_snprintf);
    ck_assert_str_eq(test_my_snprintf, test_snprintf);
}
END_TEST


START_TEST(test_snprintf_x_normal)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    int data = 12345;

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "%x", data);
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "%x", data);

    ck_assert_int_eq(len_my_snprintf, len_snprintf);
    ck_assert_str_eq(test_my_snprintf, test_snprintf);
}
END_TEST


START_TEST(test_snprintf_x_zero)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    int data = 0;

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "%x", data);
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "%x", data);

    ck_assert_int_eq(len_my_snprintf, len_snprintf);
    ck_assert_str_eq(test_my_snprintf, test_snprintf);
}
END_TEST


START_TEST(test_snprintf_x_negative_num)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    int data = -123;

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "%x", data);
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "%x", data);

    ck_assert_int_eq(len_my_snprintf, len_snprintf);
    ck_assert_str_eq(test_my_snprintf, test_snprintf);
}
END_TEST


START_TEST(test_snprintf_several_args)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    int data1 = -123;
    int data2 = -123;

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "%hd %x", data1, data2);
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "%hd %x", data1, data2);

    ck_assert_int_eq(len_my_snprintf, len_snprintf);
    ck_assert_str_eq(test_my_snprintf, test_snprintf);
}
END_TEST


START_TEST(test_snprintf_percent)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    int data = -123;

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "%hd %%", data);
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "%hd %%", data);

    ck_assert_int_eq(len_my_snprintf, len_snprintf);
    ck_assert_str_eq(test_my_snprintf, test_snprintf);
}
END_TEST


START_TEST(test_snprintf_no_args)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "12345");
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "12345");

    ck_assert_int_eq(len_my_snprintf, len_snprintf);
    ck_assert_str_eq(test_my_snprintf, test_snprintf);
}
END_TEST



Suite *snprintf_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_snprintf_hd_normal);
    tcase_add_test(tc_pos, test_snprintf_hd_zero);
    tcase_add_test(tc_pos, test_snprintf_hd_negative_num);
    tcase_add_test(tc_pos, test_snprintf_c_normal);
    tcase_add_test(tc_pos, test_snprintf_s_normal);
    tcase_add_test(tc_pos, test_snprintf_x_normal);
    tcase_add_test(tc_pos, test_snprintf_x_zero);
    tcase_add_test(tc_pos, test_snprintf_x_negative_num);
    tcase_add_test(tc_pos, test_snprintf_several_args);
    tcase_add_test(tc_pos, test_snprintf_percent);
    tcase_add_test(tc_pos, test_snprintf_no_args);


    suite_add_tcase(s, tc_pos);

    return s;
}