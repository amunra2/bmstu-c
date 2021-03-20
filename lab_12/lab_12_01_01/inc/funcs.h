#include<string.h>
#include<stdlib.h>
#include"../inc/file_work.h"
#include"../inc/sort_key.h"
#include"../inc/macrologger.h"

#ifndef FUNCS_H

#define FUNCS_H

#define OK 0
#define OK_PARSE_ARGS 0
#define OK_PARSE_FILTER 0
#define OK_PARSE_WITHOUT_FILTER 0

#define ERR_FILE_READ -2
#define ERR_STRCPY -3
#define ERR_UNRIGHT_ARGS -4
#define ERR_FILTER -5
#define ERR_WRITING_TO_FILE -7
#define ERR_UNRIGHNT_FILTER_NAME -8
#define ERR_PARSE -9

#define ERR_OPEN_LIB -10
#define ERR_LOAD_FUNC -11

#define NO_FILTER 3
#define WITH_FILTER 4
#define NO_MISTAKES 0
#define FILTER 10

#define FILE_NAME_LEN 70

int read_file(char *file_in_name, int **arr, int *len);

int parse_args(int argc, char *argv[], char *file_in_name, char *file_out_name, char *filter);

int parse_filter(int *arr_file, int len, char *file_out_name);

int parse_without_filter(int *arr_file, int len, char *file_out_name);

#endif