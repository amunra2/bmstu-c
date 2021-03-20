#include<stdio.h>
#include<stdlib.h>
#ifndef FILE_WORK_H

#define FILE_WORK_H

#define NO_MISTAKES 0
#define OK_NUM 1
#define OK_LEN 0
#define OK_FSEEK 0
#define OK_FILE 0
#define OK_READ 0
#define OK_WRITE_ELEM 0
#define OK_WRITE 0

#define ERR_FILE_CLEAR -10
#define ERR_UNRIGHNT_NUMBER -11
#define ERR_LEN_MISTAKE -12
#define ERR_MEMORY_ALLOC -13
#define ERR_READ_MISTAKE -14
#define ERR_WRITING_ELEM -15
#define ERR_NO_FILE -16
#define ERR_CLOSING_FILE -17
#define ERR_FTELL_MISTAKE -18

int read_file(char *file_in_name, int **arr, int *len);

int write_to_file(FILE *file_out, int *pb_arr, int *pe_arr);

#endif