#include"../inc/read_print.h"

 
int read_type(int *type)
{
    char *option = NULL;
    size_t len = 0;

    int check_read = getline(&option, &len, stdin);

    if ((check_read == WRONG_WORD) || (NULL == option))
    {
        return ERR_READ_TYPE;
    }

    option[strlen(option) - 1] = '\0';

    LOG_DEBUG("%ld %s", strlen(option), option);

    if (strcmp(option, "out") == EQUAL)
    {
        *type = OUT;
    }
    else if (strcmp(option, "mul") == EQUAL)
    {
        *type = MUL;
    }
    else if (strcmp(option, "sqr") == EQUAL)
    {
        *type = SQR;
    }
    else if (strcmp(option, "div") == EQUAL)
    {
        *type = DIV;
    }

    free(option);

    LOG_DEBUG("type = %d", *type);

    if (*type == NO_TYPE)
    {
        return ERR_WRONG_TYPE;
    }

    return OK_READ_TYPE;
}


int print_list(node_t *list)
{
    if (!list)
    {
        return ERR_LIST_EMPTY;
    }

    LOG_INFO("%s", "in print");

    node_t *tmp = list;

    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

    puts("L");

    return OK_PRINT_LIST;
}


