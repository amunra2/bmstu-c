#include"func.h"


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        return ERR_ARGS;
    }

    FILE *f_in = fopen(argv[1], "r");

    if (!f_in)
    {
        return ERR_NO_FILE;
    }

    node_t *list = NULL;

    int rc = read(f_in, &list);

    fclose(f_in);

    if (rc != NO_MISTAKES)
    {
        LOG_DEBUG("ERR: %d", rc);
        return rc;
    }

    if (reverse(&list) != NO_MISTAKES)
    {
        return ERR_LIST_EMPTY;
    }

    FILE *f_out = fopen(argv[2], "w");

    if (!f_out)
    {
        return ERR_NO_FILE;
    }

    if (print_list_file(f_out, list) != NO_MISTAKES)
    {
        fclose(f_out);
        return ERR_LIST_EMPTY;
    }

    fclose(f_out);

    free_list(list);

    return OK;
}