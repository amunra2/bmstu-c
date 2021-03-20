#include"../inc/check_main.h"


Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    //funcs
    s = snprintf_suite(s);

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