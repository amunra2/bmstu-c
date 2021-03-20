#include<stdio.h>
#include<stdlib.h>

#include"../inc/struct.h"

#ifndef MEMORY_WORK_H

#define MEMORY_WORK_H

#define OK_ALLOCATE 0

#define ERR_ALLOCATE_MATRIX -10

int allocate_matrix(matrix_t *matrix);

void free_matrix(matrix_t matrix);

int reallocate_matrix(matrix_t *mat, int new_row, int new_col);

#endif