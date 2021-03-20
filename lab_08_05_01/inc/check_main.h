#include<check.h>
#include<stdio.h>

#include"../inc/struct.h"
#include"../inc/memory_work.h"
#include"../inc/matrix_work.h"

#ifndef CHECK_MAIN_H

#define CHECK_MAIN_H

#define NO_MISTAKES 0

#define ERR_NOT_EQUAL_ROWS -1
#define ERR_NOT_EQUAL_COLS -2
#define ERR_UNRIGHT_ELEMS -3
#define OK_COMPARE 0


int compare_matrix(matrix_t mat1, matrix_t mat2);

void fill_matrix(matrix_t mat);

Suite *add_suite(Suite *s);
Suite *delete_suite(Suite *s);
Suite *power_suite(Suite *s);

#endif