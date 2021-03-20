#include"../inc/file_work.h"
#include"../inc/macrologger.h"


int check_file(FILE *file_in)
{
    if (fseek(file_in, 0, SEEK_END) != OK_FSEEK)
    {
        return ERR_FILE_CLEAR;
    }

    size_t current_size = ftell(file_in);

    LOG_INFO("Size of file in bytes = %ld", current_size);

    if (current_size <= 0)
    {
        return ERR_FILE_CLEAR;
    }

    return fseek(file_in, 0, SEEK_SET);
}


int array_len(FILE *file_in, int *n)
{
    int num;

    long pos_file = ftell(file_in);

    if (pos_file < 0)
    {
        LOG_ERROR("Mistake in ftell, code = %d", ERR_FTELL_MISTAKE);
        return ERR_FTELL_MISTAKE;
    }

    while (!feof(file_in))
    {
        if (fscanf(file_in, "%d", &num) != OK_NUM)
        {
            LOG_ERROR("Unright elemnt in file, code = %d", ERR_UNRIGHNT_NUMBER);
            return ERR_UNRIGHNT_NUMBER;
        }

        *n += 1;
    }

    if (fseek(file_in, 0, pos_file) != OK_FSEEK)
    {
        return ERR_LEN_MISTAKE;
    }

    return OK_LEN;
}


int fill_arr(FILE *file_in, int *pb_arr, int *pe_arr)
{
    while (pb_arr < pe_arr)
    {
        if (fscanf(file_in, "%d", pb_arr++) != OK_NUM)
        {
            LOG_ERROR("Unright element in file, code = %d", ERR_READ_MISTAKE);
            return ERR_READ_MISTAKE;
        }
    }

    return OK_READ;
}


int write_to_file(FILE *file_out, int *pb_arr, int *pe_arr)
{
    long pos_file = ftell(file_out);

    if (pos_file < 0)
    {
        LOG_ERROR("Mistake in ftell, code = %d", ERR_FTELL_MISTAKE);
        return ERR_FTELL_MISTAKE;
    }
    
    int len = pe_arr - pb_arr;

    LOG_DEBUG("Length of printing array = %d", len);

    LOG_INFO("Elements which will be print in file of length %d", len);

    while (len-- > 0)
    {
        LOG_DEBUG("elem = %d", *pb_arr);
        
        if (fprintf(file_out, "%d ", *pb_arr++) < OK_WRITE_ELEM)
        {
            LOG_ERROR("Unright element is printing in file, code = %d", ERR_FILE_CLEAR);
            return ERR_WRITING_ELEM;
        }
    }

    if (fseek(file_out, 0, pos_file) != OK_FSEEK)
    {
        return ERR_LEN_MISTAKE;
    }

    return OK_WRITE;
}

