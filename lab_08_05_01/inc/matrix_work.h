#include<stdio.h>
#include<stdlib.h>

#include"../inc/macrologger.h"
#include"../inc/struct.h"
#include"../inc/memory_work.h"
#include"../inc/parse_matrix.h"
#include"../inc/miltiplication.h"


#ifndef MATRIX_WORK_H

#define MATRIX_WORK_H

#define OK_MULTIPLICATE 0
#define OK_READ_MATRIX 0
#define OK_READ 0
#define OK_SQUARE_MATRIX 0
#define OK_EQUAL_SIZES 0
#define OK_POWER_ALL 0
#define NO_MISTAKES 0

#define OK_READ_GRADES 2

#define OK_READ_ELEM 1

#define ERR_ALLOCATE_MEMORY -1
#define ERR_UNRIGHT_ROW_INPUT -2
#define ERR_UNRIGHT_COLUMN_INPUT -3
#define ERR_UNRIGHT_MATRIX_ELEM -4
#define ERR_UNRIGHT_POWER -5


int matrix_work(void);

void print_matrix(matrix_t matrix);

#endif