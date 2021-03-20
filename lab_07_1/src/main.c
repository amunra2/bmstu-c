#include"../inc/funcs_call.h"


int main(int argc, char *argv[])
{
    char file_in_name[FILE_NAME_LEN];
    char file_out_name[FILE_NAME_LEN];
    char filter[FILTER];

    int rc = NO_MISTAKES;

    rc = parse_args(argc, argv, file_in_name, file_out_name, filter);

    if (rc != NO_MISTAKES)
    {
        LOG_DEBUG("Failed args parse, code %d", rc);
        return ERR_PARSE;
    }

    int *arr_file = NULL;
    int len = 0;

    rc = read_file(file_in_name, &arr_file, &len);

    LOG_DEBUG("Len of array from file = %d", len);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Fail in reading file, code: %d", rc);
        free(arr_file);
        return ERR_FILE_READ;
    }

    if (argc == WITH_FILTER)
    {
        rc = parse_filter(arr_file, len, file_out_name);

        if (rc != NO_MISTAKES)
        {
            return rc;
        }
    }
    else if (argc == NO_FILTER)
    {
        rc = parse_without_filter(arr_file, len, file_out_name);

        if (rc != NO_MISTAKES)
        {
            return rc;
        }
    }

    return OK;
}