#include<stdio.h>
#include<math.h>
#include<limits.h>

#include"../inc/macrologger.h"
#include"../inc/struct.h"
#include"../inc/memory_work.h"

#ifndef MULTIPLICATION_H

#define MULTIPLICATION_H

#define OK_MULTI 0
#define NO_MISTAKES 0
#define OK 0

#define OWERFLOW 1

#define ERR_INT_OVERFLOW -20

int multi(matrix_t a_mat, matrix_t b_mat, matrix_t *result);

int power_matrix(matrix_t matrix, matrix_t *result, int grade);

#endif