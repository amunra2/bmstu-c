#include<stdio.h>
#include<stdlib.h>
#include"macrologger.h"


#ifndef FUNC_H

#define FUNC_H

#define NO_MISTAKES 0


#define OK 0
#define OK_ALLOCATE 0
#define OK_READ 0
#define OK_DELETE_ROW 0
#define OK_CHANGE 0

#define ERR_READ_SIZE -1
#define ERR_ALLOCATE_MATRIX -2

#define ERR_READ_ELEM -3


typedef struct
{
    int **matrix;

    int n;
    int m;
} matrix_t;

void free_matrix(matrix_t mat);

int allocate_matrix(matrix_t *mat);

int read_matrix(matrix_t *mat);

void print_matrix(matrix_t mat);

int check_delete(matrix_t *mat);

void change_elems(matrix_t *mat);

#endif