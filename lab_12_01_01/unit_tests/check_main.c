#include"../inc/check_main.h"


int compare_arrs(int *arr1, int len1, int *arr2, int len2)
{
    if (len1 != len2)
    {
        return ERR_NOT_EQUAL_LENGTHS;
    }

    for (int ind = 0; ind < len1; ind++)
    {
        if (arr1[ind] != arr2[ind])
        {
            return ERR_ARRS_DIFFERENT;
        }
    }

    return OK_COMPARE;
}


Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    //funcs
    s = sort_suite(s);
    s = key_suite(s);

    return s;
}


int main(void)
{
    Suite *s = tests_suite();

    SRunner *runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    int mistakes = srunner_ntests_failed(runner);

    srunner_free(runner);

    return mistakes;
}