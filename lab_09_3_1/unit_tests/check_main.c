#include"../inc/check_main.h"


int compare_arrs(product_t *arr1, int len1, product_t *arr2, int len2)
{
    if (len1 != len2)
    {
        return ERR_NOT_EQUAL_LENGTHS;
    }

    for (int ind = 0; ind < len1; ind++)
    {
        arr1[ind].name[strlen(arr1[ind].name) - 1] = '\0';

        if ((strcmp(arr1[ind].name, arr2[ind].name) != 0) || (arr1[ind].price != arr2[ind].price))
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
    s =  read_suite(s);

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