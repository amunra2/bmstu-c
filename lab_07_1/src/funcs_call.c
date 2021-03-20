#include"../inc/funcs_call.h"
#include"../inc/macrologger.h"


int parse_args(int argc, char *argv[], char *file_in_name, char *file_out_name, char *filter)
{
    if ((argc != NO_FILTER) && (argc != WITH_FILTER))
    {
        LOG_ERROR("Unright num of arguments, argc = %d, code: %d", argc, ERR_UNRIGHT_ARGS);
        return ERR_UNRIGHT_ARGS;
    }

    if ((NULL == strcpy(file_in_name, argv[1])) || (NULL == strcpy(file_out_name, argv[2])))
    {
        LOG_ERROR("Error in strcpy, code: %d", ERR_STRCPY);
        return ERR_STRCPY;
    }


    if (argc == WITH_FILTER)
    {
        if (NULL == strcpy(filter, argv[3]))
        {
            LOG_ERROR("Error in strcpy, code: %d", ERR_STRCPY);
            return ERR_STRCPY;
        }

        if (strcmp(filter, "f"))
        {
            LOG_ERROR("Unright filter name, code: %d", ERR_UNRIGHNT_FILTER_NAME);
            return ERR_UNRIGHNT_FILTER_NAME;
        }

    }

    return OK_PARSE_ARGS;
}



int parse_filter(int *arr_file, int len, char *file_out_name)
{
    int *filtered_arr_begin = NULL;
    int *filtered_arr_end = NULL;

    int rc = key(arr_file, arr_file + len, &filtered_arr_begin, &filtered_arr_end);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Fails in filtraton func, code: %d", rc);
        free(filtered_arr_begin);
        free(arr_file);
        return ERR_FILTER;
    }

    free(arr_file);

    int count_len = filtered_arr_end - filtered_arr_begin;

    LOG_DEBUG("Length of filtered array = %d", count_len);

    mysort(filtered_arr_begin, count_len, sizeof(int), compare);

    FILE *file_out = fopen(file_out_name, "w");

    if (!file_out)
    {
        LOG_ERROR("Fail in opening of file, code: %d", ERR_NO_FILE);
        free(filtered_arr_begin);
        return ERR_NO_FILE;
    }

    rc = write_to_file(file_out, filtered_arr_begin, filtered_arr_begin + count_len);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Fails in writing to file func, code: %d", rc);
        free(filtered_arr_begin);
        return ERR_WRITING_TO_FILE;
    }

    if (fclose(file_out) != NO_MISTAKES)
    {
        LOG_ERROR("Failed closing file, code: %d", ERR_CLOSING_FILE);
        free(filtered_arr_begin);
        return ERR_CLOSING_FILE;
    }

    free(filtered_arr_begin);

    return OK_PARSE_FILTER;
}



int parse_without_filter(int *arr_file, int len, char *file_out_name)
{
    mysort(arr_file, len, sizeof(int), compare);

    FILE *file_out = fopen(file_out_name, "w");

    if (!file_out)
    {
        LOG_ERROR("Fail in opening of file, code: %d", ERR_NO_FILE);
        free(arr_file);
        return ERR_NO_FILE;
    }

    int rc = write_to_file(file_out, arr_file, arr_file + len);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Fails in writing to file func, code: %d", rc);
        free(arr_file);
        return ERR_WRITING_TO_FILE;
    }

    if (fclose(file_out) != NO_MISTAKES)
    {
        LOG_ERROR("Failed closing file, code: %d", ERR_CLOSING_FILE);
        free(arr_file);
        return ERR_CLOSING_FILE;
    }

    free(arr_file);

    return OK_PARSE_WITHOUT_FILTER;
}