#include"../inc/main_inc.h"


int main(int argc, char *argv[])
{
    char file_in_name[FILE_NAME_LEN];
    char file_out_name[FILE_NAME_LEN];

    int rc = NO_MISTAKES;

    rc = parse_args(argc, argv, file_in_name, file_out_name);

    if (rc != NO_MISTAKES)
    {
        LOG_DEBUG("Failed args parse, code %d", rc);
        return ERR_PARSE;
    }

    rc = execute_task(file_in_name, file_out_name);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    return OK;
}