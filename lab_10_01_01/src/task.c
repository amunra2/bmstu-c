#include"../inc/task.h"


int parse_args(int argc, char *argv[], char *file_in_name, char *file_out_name)
{
    if (argc != 3)
    {
        LOG_ERROR("Unright num of arguments, argc = %d, code: %d", argc, ERR_UNRIGHT_ARGS);
        return ERR_UNRIGHT_ARGS;
    }

    if ((NULL == strcpy(file_in_name, argv[1])) || (NULL == strcpy(file_out_name, argv[2])))
    {
        LOG_ERROR("Error in strcpy, code: %d", ERR_STRCPY);
        return ERR_STRCPY;
    }

    return OK_PARSE_ARGS;
}


int swap_first_last(node_t **list)
{
    void *first_elem = pop_front(list);

    if (!first_elem)
    {
        return ERR_LIST_EMPTY;
    }

    void *last_elem = pop_back(list);

    if (!last_elem)
    {
        return ERR_LIST_EMPTY;
    }

    if (push_node_front(list, last_elem) != NO_MISTAKES)
    {
        return ERR_PUSH_NODE;
    }

    if (push_node_back(list, first_elem) != NO_MISTAKES)
    {
        return ERR_PUSH_NODE;
    }

    return OK_SWAP;
}


int execute_task(char *file_in_name, char *file_out_name)
{
    node_t *list = NULL;
    arr_t arr = {.data = NULL, .len = 0};

    LOG_INFO("%s","it works");

    int rc = NO_MISTAKES;

    rc = fill_list(file_in_name, &list, &arr);

    if (rc != NO_MISTAKES)
    {
        free(arr.data);
        LOG_ERROR("%d", rc);
        return rc;
    }

    node_t *sorted_list = sort(list, comparator);

    if (!sorted_list)
    {
        free(arr.data);
        return ERR_SORT_LIST;
    }

    rc = swap_first_last(&sorted_list);

    if (rc != NO_MISTAKES)
    {
        free(arr.data);
        free(sorted_list);
        LOG_ERROR("%d", rc);
        return rc;
    }

    node_t *reveresed_list = reverse(sorted_list);

    if (!reveresed_list)
    {
        free(arr.data);
        return ERR_REVERSE_LIST;
    }

    rc = write_file_list(file_out_name, reveresed_list);

    if (rc != NO_MISTAKES)
    {
        free_list(reveresed_list);
        free(arr.data);
        return rc;
    }

    free_list(reveresed_list);
    free(arr.data);

    return OK_TASK;
}