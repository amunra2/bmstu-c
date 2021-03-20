#include<dlfcn.h>
#include<stdio.h>
#include"../inc/funcs.h"
#include"../inc/macrologger.h"

// Sort key 

typedef int (*fn_key_t) (const int *pb_src, const int *per_src, int **pd_dst, int **pe_dst);

typedef void (*fn_mysort_t) (void *base, size_t num, size_t size, int (*compare)(const void *, const void *));

typedef int* (*fn_find_min_t) (int *pb_src, int *pe_src);

typedef int* (*fn_find_max_t) (int *pb_src, int *pe_src);

typedef int (*fn_compare_t) (const void *p1, const void *p2);

// Read write

typedef int (*fn_array_len_t) (FILE *file_in, int *n);

typedef int (*fn_check_file_t) (FILE *file_in);

typedef int (*fn_fill_arr_t) (FILE *file_in, int *pb_arr, int *pe_arr);

typedef int (*fn_write_to_file_t) (FILE *file_out, int *pb_arr, int *pe_arr);



int read_file(char *file_in_name, int **arr, int *len)
{
    void *hlib = dlopen("./libs/lib_io_sort.so", RTLD_NOW);

    if (!hlib)
    {
        LOG_DEBUG("Error lib open, %s", dlerror());

        return ERR_OPEN_LIB;
    }

    fn_check_file_t check_file = (fn_check_file_t) dlsym(hlib, "check_file");

    if (!check_file)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }

    fn_array_len_t array_len = (fn_array_len_t) dlsym(hlib, "array_len");

    if (!array_len)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }

    fn_fill_arr_t fill_arr = (fn_fill_arr_t) dlsym(hlib, "fill_arr");

    if (!fill_arr)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }        

    FILE *file_in = fopen(file_in_name, "r");

    if (!file_in)
    {
        LOG_ERROR("Error file is not exist, code: %d", ERR_NO_FILE);
        return ERR_NO_FILE;
    }

    if (check_file(file_in) != OK_FILE)
    {
        LOG_ERROR("File is clear, code = %d", ERR_FILE_CLEAR);
        return ERR_FILE_CLEAR;
    }

    int rc = NO_MISTAKES;
    int n = 0;

    rc = array_len(file_in, &n);

    LOG_DEBUG("Array from file length = %d", n);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Unright len of array, code = %d", ERR_LEN_MISTAKE);
        return ERR_LEN_MISTAKE;
    }

    int *file_arr = NULL;

    file_arr = malloc(n * sizeof(int));

    if (NULL == file_arr)
    {
        return ERR_MEMORY_ALLOC;
    }

    rc = fill_arr(file_in, file_arr, file_arr + n);

    if (rc != NO_MISTAKES)
    {
        LOG_ERROR("Filling array is failed, code = %d", ERR_FILE_CLEAR);
        return ERR_READ_MISTAKE;
    }

    *len = n;
    *arr = file_arr;

    if (fclose(file_in) != NO_MISTAKES)
    {
        LOG_ERROR("Faild file close, code: %d", ERR_CLOSING_FILE);
        free(*arr);
        return ERR_CLOSING_FILE;
    }

    dlclose(hlib);

    return OK_READ;
}


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
    void *hlib = dlopen("./libs/lib_io_sort.so", RTLD_NOW);

    if (!hlib)
    {
        LOG_DEBUG("Error lib open, %s", dlerror());

        return ERR_OPEN_LIB;
    }

    fn_key_t key = (fn_key_t) dlsym(hlib, "key");

    if (!key)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }

    fn_mysort_t mysort = (fn_mysort_t) dlsym(hlib, "mysort");

    if (!mysort)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }

    fn_compare_t compare = (fn_compare_t) dlsym(hlib, "compare");

    if (!compare)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }

    fn_find_min_t find_min = (fn_find_min_t) dlsym(hlib, "find_min");

    if (!find_min)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }

    fn_find_max_t find_max = (fn_find_max_t) dlsym(hlib, "find_max");

    if (!find_max)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }

    fn_write_to_file_t write_to_file = (fn_write_to_file_t) dlsym(hlib, "write_to_file");

    if (!write_to_file)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }

    int *el_min = find_min(arr_file, arr_file + len);

    int *el_max = find_max(arr_file, arr_file + len);

    if (el_min == el_max)
    {
        LOG_ERROR("Max and min are the same, code %d", ERR_THE_SAME_ELEMENTS);
        return ERR_THE_SAME_ELEMENTS;
    }

    int size = MAX(el_min, el_max) - MIN(el_min, el_max) - 1;

    LOG_DEBUG("Size of new array : %d", size);

    if (size < 1)
    {
        LOG_ERROR("Not enough elements in new array, size = %d, code %d ", size, ERR_UNRIGHT_SIZE);
        return ERR_UNRIGHT_SIZE;
    }

    int *filtered_arr_begin = malloc(size * sizeof(int));

    if (!filtered_arr_begin)
    {
        return ERR_MEMORY_ALLOCATE;
    }

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

    dlclose(hlib);

    return OK_PARSE_FILTER;
}



int parse_without_filter(int *arr_file, int len, char *file_out_name)
{
    void *hlib = dlopen("./libs/lib_io_sort.so", RTLD_NOW);

    if (!hlib)
    {
        LOG_DEBUG("Error lib open, %s", dlerror());

        return ERR_OPEN_LIB;
    }

    fn_mysort_t mysort = (fn_mysort_t) dlsym(hlib, "mysort");

    if (!mysort)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }

    fn_compare_t compare = (fn_compare_t) dlsym(hlib, "compare");

    if (!compare)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }

    fn_write_to_file_t write_to_file = (fn_write_to_file_t) dlsym(hlib, "write_to_file");

    if (!write_to_file)
    {
        LOG_DEBUG("Error connect func, %s", dlerror());
        return ERR_LOAD_FUNC;
    }

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

    dlclose(hlib);

    return OK_PARSE_WITHOUT_FILTER;
}