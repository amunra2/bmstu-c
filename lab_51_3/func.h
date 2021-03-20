#ifndef FUNC_H
#define FUNC_H

#define NOT_ENOUGH_ARGUMENTS -1
#define FILE_EXIST_ERR -2
#define SORTING_FAIL -3
#define PRINTING_FAIL -4
#define FILE_CLEAR_ERR -5
#define OK 0

#define SIZE_OK 0
#define SORT_OK 0
#define PRINT_OK 0
#define MISTAKE_SIZE -1

void create_bin(FILE *f, char *count_str);

int size_of_file(FILE *f, size_t *size);
int print_bin(FILE *f);

int sort_bin(FILE *f);


#endif