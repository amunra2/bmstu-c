#include"../inc/check_main.h"


int compare_lists(node_t *list1, node_t *list2)
{
    while (list1 != NULL)
    {
        if (list1->data != list2->data)
        {
            return ERR_LISTS_DIFFERENT;
        }

        list1 = list1->next;
        list2 = list2->next;
    }

    if (list2 != NULL)
    {
        return ERR_LISTS_DIFFERENT;
    }

    return OK_COMPARE;
}


Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    //funcs
    s = multi_suite(s);
    s = div_suite(s);

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